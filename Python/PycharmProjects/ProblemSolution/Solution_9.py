import turtle
import random

counts = random.randint(4, 6)
# counts代表雪花数量，这里我们随机生成4-6片雪花
def snowflake():
    for i in range(counts):
        # 随机移动雪花中心的位置
        coordinate_x = random.randint(-300, 300)
        coordinate_y = random.randint(-200, 200)
        move_pen_position(x=coordinate_x, y=coordinate_y)
        # 设置雪花的大小，这样可以让每一片雪花都不一样
        random_size = random.randint(30, 50)
        for j in range(7):
            branch(size=random_size)
def move_pen_position(x, y):
    turtle.hideturtle()
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.showturtle()
# 下面的branch()函数用来绘制雪花的单个枝干
def branch(size):
    angle = 360 / 7
    turtle.right(angle)
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

# 下面的paint()函数用来设置整体属性
def paint():
    turtle.setup(800, 600)
    turtle.screensize(400, 200, 'skyblue')
    turtle.pencolor('grey')
    turtle.speed(5)
    turtle.pensize(2)
    snowflake()
    # 下面的诗句仅仅是为了意境而存在，大家也可以换成自己喜欢的诗句
    move_pen_position(x=200, y=-250)
    message = "白雪缺嫌春色晚，故穿庭树作飞花"
    turtle.write(message, align='center', font=('宋体',15,'normal'))
    turtle.done()

paint()
