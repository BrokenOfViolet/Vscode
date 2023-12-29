class Settings:
    def __init__(self):
        self.screen_width = 800
        self.screen_height = 600
        self.bg_color = (230,230,230)
        
        self.ship_speed = 3.0
        
        self.bullet_speed = 5.0
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = (60,60,60)
        self.bullet_allowed = 30
        # restrict the number of bullets (to encourage player to shoot purposely)

        self.alien_speed = 1.0
        self.fleet_drop_speed = 10
        self.fleet_direction = 1
        # the digit 1 means the direction of alien. 1 for rigth, -1 for left
        
        self.ship_limit = 3
        
        