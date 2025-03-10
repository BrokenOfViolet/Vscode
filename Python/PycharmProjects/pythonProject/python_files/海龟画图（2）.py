import turtle
import datetime

Now = datetime.datetime.now()
Now = Now.strftime("%Y-%m-%d %H:%M:%S")


def TurtlePaint(name, Nowtime):
    def heart_arc():
        turtle.speed(50)
        for i in range(200):
            turtle.right(1)
            turtle.forward(2)

    def move_pen_position(x, y):
        turtle.hideturtle()
        turtle.up()
        turtle.goto(x, y)
        turtle.down()
        turtle.showturtle()

    turtle.setup(width=800, height=600)
    turtle.color('black', 'Pink')
    turtle.pensize(5)
    turtle.speed(2)

    move_pen_position(x=0, y=-90)
    turtle.left(140)

    turtle.begin_fill()

    turtle.forward(224)
    heart_arc()
    turtle.left(120)
    heart_arc()

    turtle.forward(224)
    turtle.end_fill()

    move_pen_position(x=0, y=-240)
    turtle.color('red', 'Pink')
    name = "To" + name + "\n" + "Hope you happy everyday."
    turtle.write(name, font=('Ariel', 20, 'bold'), align='center')

    move_pen_position(x=200, y=-270)
    turtle.write(Nowtime, font=('Ariel', 10, 'bold'), align='right')

    window = turtle.Screen()
    window.exitonclick()


name = input("What's your name?\n")
TurtlePaint(name=name, Nowtime=Now)