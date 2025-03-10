import pygame
import sys
from time import sleep

from settings import Settings
from game_stats import GameStates
from ship import Ship
from alien import Alien
from bullet import Bullet

class AlienInvasion:
    def __init__(self):
        pygame.init()
        self.clock = pygame.time.Clock()
        self.settings = Settings()
        
        self.screen = pygame.display.set_mode((self.settings.screen_width,self.settings.screen_height))
        pygame.display.set_caption("Alien Invasion")
        
        self.game_active = True
        self.stats = GameStates(self)
        
        self.ship = Ship(self)
        self.bullets = pygame .sprite.Group()
        self.aliens = pygame.sprite.Group()
        
        self._create_fleet()
        
    def run_game(self):
        while True:
            self._check_events()
            
            if self.game_active:
                self.ship.update()
                self._update_bullets()               
                self._update_aliens() 
                                   
            self._update_screen()
            

            self.clock.tick(60)

    
    def _check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            # Here I use mouse event to match ship's action because my mac key
            # event seemed to happend to some problems, but the former works
            elif event.type == pygame.MOUSEBUTTONDOWN:
                self._check_mousedown_events(event)
            elif event.type == pygame.MOUSEBUTTONUP:
                self._check_mouseup_events(event)
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)
            elif event.type == pygame.KEYUP:
                pass
    
    def _check_mousedown_events(self, event):
        if event.button == 3:               # event.button == 3 --> 鼠标右键 
            self.ship.moving_right = True
        elif event.button == 1:             # event.button == 1 --> 鼠标左键
            self.ship.moving_left = True
        elif event.button == 2:
            self.ship.shoot =  True if self.ship.shoot == False else False
            
    def _check_mouseup_events(self, event):
        if event.button == 3:
            self.ship.moving_right = False
        elif event.button == 1:
            self.ship.moving_left = False        
    
    def _check_keydown_events(self, event):
        if event.type == pygame.K_q:
            sys.exit()
        elif event.type == pygame.K_SPACE:
            self._fire_bullet()
            
    def _update_bullets(self):
        self.bullets.update()
        for bullet in self.bullets.copy():  # 遍历副本而不是直接遍历原始列表是为了确保在对列表进行修改时不会影响到遍历过程的稳定性和正确性
            if bullet.rect.bottom <= 0:
                self.bullets.remove(bullet)
        self._check_bullet_alien_collisions()
        if self.ship.shoot:
            self._fire_bullet()
                        
    def _check_bullet_alien_collisions(self):
        collisions = pygame.sprite.groupcollide(self.bullets, self.aliens,
                                                True, True)
        """具体地说,pygame.sprite.groupcollide() 函数会检查两个精灵组中的所有精灵对象，如果发现某个子弹精灵和外星人精灵发生了碰撞，
        那么这两个精灵就会被标记为碰撞。而当函数中指定了 True, True 这两个参数时，表示发生碰撞的子弹和外星人都会被移除
        （从它们所在的精灵组中删除）"""
        if not self.aliens:
            self.bullets.empty()
            self._create_fleet()
        
    def _fire_bullet(self):
        if len(self.bullets) < self.settings.bullet_allowed:
            new_bullet = Bullet(self)
            self.bullets.add(new_bullet)
    
    def _create_fleet(self):
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        # attribute <rect.size> is a tuple which include width and height
        
        current_x, current_y = alien_width, alien_height
        while current_y < (self.settings.screen_height - 3 * alien_height):
            while current_x < (self.settings.screen_width-2 * alien_width):
                self._create_alien(current_x, current_y)
                current_x += 2 * alien_width

            current_x = alien_width
            current_y += 2 * alien_height

        
    def _create_alien(self, x_position, y_position):
        new_alien = Alien(self)
        new_alien.x = x_position
        new_alien.rect.x = x_position
        new_alien.rect.y = y_position
        self.aliens.add(new_alien)
        
    def _update_aliens(self):
        self._check_fleet_edges()
        self._check_aliens_bottom()
        
        self.aliens.update()
        
        if pygame.sprite.spritecollideany(self.ship, self.aliens):
            self._ship_hit()
        """当这段代码执行时，它会检测玩家飞船(self.ship)与外星人精灵组(self.aliens)中的任何外星人精灵是否发生了碰撞。如果检测到发生了碰撞,
        则 pygame.sprite.spritecollideany() 函数会返回第一个发生碰撞的外星人精灵，如果没有发生碰撞，则返回 None"""

    def _check_fleet_edges(self):
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    
    def _change_fleet_direction(self):
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *= -1
                
                
    def _ship_hit(self):
        if self.stats.ship_left > 0:
            self.stats.ship_left -= 1
            
            self.bullets.empty()
            self.aliens.empty()
            
            self._create_fleet()
            self.ship.center_ship()
        
            sleep(0.5)
        else:
            self.game_active = False
        
    def _check_aliens_bottom(self):
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= self.settings.screen_height:
                self._ship_hit()
                break
                            
    def _update_screen(self):
        self.screen.fill(self.settings.bg_color)
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
    
        self.ship.blitme()
        self.aliens.draw(self.screen)
        
        pygame.display.flip()
        
    
if __name__ == '__main__':
    ai = AlienInvasion()
    ai.run_game()