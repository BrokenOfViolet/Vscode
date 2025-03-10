# 过年的时候，小 hi 看到大家人手一个冰墩墩，可羡慕了，然后 zax 说他会，用 python
# 给小 hi 画了一个，但是小 hi 还是不满足，说她想要更可爱的，这可怎么办，谁能满足小 hi
# 的愿望呢？（大家可以随便画，各种类型的都可以，期待大家的作品哦）（要求提交源代码以
# 及运行结果截图或视频）
# 冬天要到了，我叶怡萍今天就为大家画一下雪花❄️

import turtle
import random


counts = random.randint(3, 5)


def sonwoflake():
    turtle.pencolor()
    turtle.speed(4)
    turtle.pensize()
    for i in range(counts):
        coordinate_x = random.randint(-300, 300)
        coordinate_y = random.randint(-200, 200)
        move_pen_position(x=coordinate_x, y=coordinate_y)
        for j in range(7):
            branch()
    turtle.done()


def move_pen_position(x, y):
    turtle.hideturtle()
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.showturtle()


def branch():
    angle = 360 / 7
    turtle.right(angle)
    size = 60
    turtle.forward(size)
    turtle.backward(size/3)
    turtle.right(30)
    turtle.forward(size/3)
    turtle.backward(size/3)
    turtle.left(60)
    turtle.forward(size/3)
    turtle.backward(size/3)
    turtle.right(30)
    turtle.backward(2*size/3)


def paint():
    turtle.setup(800, 600)


sonwoflake()