import pygame
import sys

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Collision_ball")

ball = pygame.image.load('/Users/mac/vscode/Python/collison_ball/images/star.png')
ballrect = ball.get_rect()

screen.blit(ball, ballrect)
clock = pygame.time.Clock()

while True:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    screen.blit(screen, ballrect)
    screen.fill((255, 255, 255))

    pygame.display.flip()
