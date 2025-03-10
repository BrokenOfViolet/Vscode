# 数据信息如下：
# 数据第一行给出两个正整数 m，n；
# 接下来 m 行，每一行给出两个数字，分别是城市横纵坐标, 两个数字用空格隔开；
# 接下来 n 行，每一行给出两个数字，代表存在从城市 x1 到城市 x2 之间有道路，两个数
# 字用空格隔开。
# 数据见附件二。
# 约定：
# 必然可以从任意城市出发到达任意城市。


import turtle
import re

with open(r'material/附件2.txt', 'r') as file:
    text = file.read()
    text.encode('utf-8')
    values = re.findall('(\d+)', text)
    file.close()

values = values[2:34]
stand = 0

locations = []
coordinates = []
for coordinate in values:
    coordinates.append(int(coordinate))
    locations.append(coordinates)
    stand = stand + 1
    if stand % 2 == 0:
        coordinates = []


def paintmap():
    turtle.screensize(800, 600, 'pink')
    turtle.setup(1000, 650, startx=200, starty=100)
    turtle.pensize(3)
    turtle.pencolor('purple')

    turtle.hideturtle()

    def move_pen_position(x, y):
        turtle.hideturtle()
        turtle.penup()
        turtle.goto(x, y)
        turtle.pendown()
        turtle.showturtle()

    def write_location():
        pass

    for location in locations:
        turtle.goto(location[0]-500, location[1]-325)
        city = str(location[0]-500) + ',' + str(location[1]-325)
        turtle.write(city)
    turtle.done()


paintmap()