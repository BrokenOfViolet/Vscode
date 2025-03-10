import turtle as t

def move_pen_position(x,y):
    t.hideturtle()
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.showturtle()


def draw_wreath():
    t.pensize(1)
    t.speed(0)
    radius = 150
    colors = ["purple","blue","green","yellow","orange","red","violet","pink"]
    for color in colors:
        t.fillcolor(color)
        t.begin_fill()
        t.circle(radius)
        t.end_fill()
        radius -= 15

def draw_peacock():
    t.speed(3)
    move_pen_position(0,0)          # draw body
    t.fillcolor('beige')
    t.begin_fill()
    t.seth(0)
    t.fd(20)
    t.left(90)
    t.fd(140)
    t.right(90)
    t.circle(20,270)
    t.fd(160)
    t.end_fill()
    move_pen_position(20,160)
    t.fillcolor('black')            # draw eye
    t.begin_fill()
    t.circle(3)
    t.end_fill()
    t.fillcolor('yellow')           # draw mouth
    t.seth(0)               
    move_pen_position(40,160)
    t.right(30)
    t.fd(15)
    t.right(150)
    t.fd(20)
    move_pen_position(0,0)          # draw feet
    for i in range(2):              
        t.seth(270)
        t.fd(50)
        t.backward(20)
        t.left(20)
        t.fd(22)
        t.backward(22)
        t.seth(250)
        t.fd(22)
        t.seth(270)
        move_pen_position(20,0)
    angle = 0
    for i in range(3):
        move_pen_position(20,180)
        t.seth(60+angle)
        angle += 30
        t.fd(20)

def write():
    move_pen_position(0,-120)
    t.write("bbz niubi 666!", align="center", font=("Arial", 12, "bold"))



draw_wreath()
draw_peacock()
write()
t.mainloop()



