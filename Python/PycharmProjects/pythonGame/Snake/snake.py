import pygame


class cube(object):
    rows = 0
    w = 0
    def __init__(self, start, dirnx=1, dirny=0, color=(255, 0, 0)):
        pass

    def move(self, dirnx, dirny):
        pass

    def draw(self, surface, eyes=False):
        pass


class snake(object):
    def __init__(self, color, pos):
        pass

    def move(self):
        pass

    def reset(self, pos):
        pass

    def addCube(self):
        pass

    def draw(self, surface):
        pass


def drawGrid(w, rows, surface):
    x = 0
    y = 0
    sizeBtwn = w//rows
    for i in range(rows):
        x += sizeBtwn
        y += sizeBtwn

        pygame.draw.line()


    pass

def redrwaWindow():
    global width, rows


def randomSnake():
    pass

def message():
    pass

def main():
    global width, rows
    width = 500
    rows = 25
    win = pygame.display.set_mode((width, width))
    s = snake((255, 0, 0), (10, 10))
    clock = pygame.time.Clock()
    flag = True

    while flag:
        clock.tick(50)