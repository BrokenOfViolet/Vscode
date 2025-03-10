import pygame
import random

# 初始化Pygame
pygame.init()

# 屏幕尺寸
width, height = 800, 600
screen = pygame.display.set_mode((width, height))

# 定义字符集
chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_-+=[]{}|;:,.<>?/~"

# 定义单个代码雨的类
class CodeRain:
    def __init__(self):
        self.x = random.randint(0, width)
        self.y = random.randint(-height, 0)
        self.speed = random.randint(5, 15)
        self.char = random.choice(chars)
        self.color = (0, 255, 0)  # 绿色
    
    def fall(self):
        self.y += self.speed
        if self.y > height:
            self.y = random.randint(-height, 0)
            self.speed = random.randint(5, 15)
            self.char = random.choice(chars)
    
    def draw(self, screen):
        font = pygame.font.SysFont(None, 36)  # 字体大小为36
        text = font.render(self.char, True, self.color)
        screen.blit(text, (self.x, self.y))

# 创建代码雨列表
code_rains = [CodeRain() for _ in range(100)]

# 主循环
running = True
while running:
    screen.fill((0, 0, 0))  # 清空屏幕
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # 更新和绘制代码雨
    for code_rain in code_rains:
        code_rain.fall()
        code_rain.draw(screen)
    
    pygame.display.flip()  # 刷新屏幕

pygame.quit()
