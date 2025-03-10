import pygame
import sys
import random


class Bird(object):
    def __init__(self):
        pass

    def birdUpdate(self):
        pass


class Pipeline(object):
    def __init__(self):
        pass


def CreatMap():
    screen.fill(color)
    screen.blit(background, (0, 0))
    pygame.display.update()


if __name__ == '__main__':
    pygame.init()
    size = width, height = 488, 650
    screen = pygame.display.set_mode(size)
    clock = pygame.time.Clock()
    color = (255, 255, 255)
    bird = Bird()
    pipeline = Pipeline()
    while True:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        background = pygame.image.load(r"../pictures/night.png")
        CreatMap()
