import pygame
import sys

pygame.init()
screen = pygame.display.set_mode((800,600))
pygame.display.set_caption("Sky Blue")

droplet = pygame.image.load("/Users/mac/vscode/Python/Alien_Invasion/images/raindrop.png")
droplet_rect = droplet.get_rect()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    
    screen.fill((10,10,200))
    screen.blit(droplet, droplet_rect)
    
    droplet_rect.topleft = (400, 300)

    pygame.display.flip()