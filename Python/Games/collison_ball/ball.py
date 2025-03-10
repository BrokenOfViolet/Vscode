import pygame
import sys

pygame.init()
size = width, height = 800, 600
screen = pygame.display.set_mode(size)
color = (255, 255, 255)

ball = pygame.image.load('Games/collison_ball/images/snowball.png')
ballrect = ball.get_rect()              # set a rect aera

speed = [5, 5]
clock = pygame.time.Clock()
while True:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    ballrect = ballrect.move(speed)
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]

    screen.fill(color)
    screen.blit(ball, ballrect)
    pygame.display.flip()
            