import turtle

wn = turtle.Screen()
wn.title("The Pong Game Window")
wn.bgcolor("black")
wn.setup(width=800, height=600)
wn.tracer(0)


paddle_a = turtle.Turtle()
paddle_a.shape("square")
paddle_a.color("white")
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup()
paddle_a.goto(x=-350, y=0)

paddle_b = turtle.Turtle()
paddle_b.shape("square")
paddle_b.color("white")
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(x=350, y=0)

ball = turtle.Turtle()
ball.shape("square")
ball.color("white")
ball.penup()
ball.goto(0, 0)

def paddle_a_up():
    y = paddle_a.ycor()
    y += 20
    paddle_a.sety(y)

def paddle_a_down():
    y = paddle_a.ycor()
    y -= 20
    paddle_a.sety(y)


wn.listen()
wn.onkeypress(paddle_a_up, 'w')
wn.onkeypress(paddle_a_down, 's')

while True:
    wn.update()