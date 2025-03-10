import turtle


def TurtlePaint(name):
    def finger(length):
        turtle.speed(18)
        turtle.forward(length)
        turtle.circle(50, 180)
        turtle.forward(length)
        turtle.right(180)

    def move_pen_position(x, y):
        turtle.hideturtle()
        turtle.penup()
        turtle.goto(x, y)
        turtle.pendown()
        turtle.showturtle()

    turtle.setup(800, 600)
    turtle.pensize(5)
    move_pen_position(x=250, y=-160)
    turtle.left(90)

    finger(200)
    finger(220)
    finger(340)
    finger(220)
    finger(200)

    move_pen_position(x=0, y=-245)
    insult = "Fuck you!"
    turtle.write(insult, font=('', 50, 'bold'), align='center')
    move_pen_position(x=0, y=-290)
    turtle.write(name, font=('', 50, 'bold'), align='center')
    window = turtle.Screen()
    window.exitonclick()


name = input("What's your name?\n")
TurtlePaint(name=name)