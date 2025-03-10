import turtle

PADDLE_XPOSITION = 350
PADDLE_SPEED = 20

score_A = 0
score_B = 0


window = turtle.Screen()
window.title("The Pong Game Window")
window.setup(width=800, height=600)
window.bgcolor('black')
window.tracer(0)

class Paddle:
    def __init__(self, corrdinate_x):
        self.position = corrdinate_x
        self.paddle = turtle.Turtle()
        self.paddle.color("white")
        self.paddle.speed(0)
        self.paddle.shape("square")
        self.paddle.shapesize(stretch_wid=5, stretch_len=1)
        self.paddle.penup()
        self.paddle.goto(x=corrdinate_x,y=0)

    def move_up(self):
        self.paddle.sety(self.paddle.ycor()+PADDLE_SPEED)

    def move_down(self):
        self.paddle.sety(self.paddle.ycor()-PADDLE_SPEED)

    def keyboard_control(self):
        window.listen()
        if self.position < 0:
            window.onkeypress(self.move_up, 'w')
            window.onkeypress(self.move_down, 's')
        else:
            window.onkeypress(self.move_up, 'Up')
            window.onkeypress(self.move_down, 'Down')

class Ball:
    def __init__(self):
        self.dy = 2
        self.dx = 2
        self.ball = turtle.Turtle()
        self.ball.color("white")
        self.ball.shape("square")
        self.ball.speed(0)
        self.ball.penup()
        self.ball.goto(0,0)

    def move(self):
        self.ball.goto(self.ball.xcor()+self.dx, self.ball.ycor()+self.dy)

    def collision_check(self):
        x_position = self.ball.xcor()
        y_position = self.ball.ycor()
        if x_position > 390 or x_position < -390:
            self.dx *= -1
        if y_position > 290 or y_position < -290:
            self.dy *= -1


class Pen:
    def __init__(self):
        self.pen = turtle.Turtle()
        self.pen.speed(0)
        self.pen.color("white")
        self.pen.penup()
        self.pen.hideturtle()
        self.pen.goto(x=0, y=260)

    def write(self):
        self.pen.write(f'Player A : {score_A}     Player B : {score_B}', align="center", font=('Courier',24,'normal'))


paddle_a = Paddle(-PADDLE_XPOSITION)
paddle_b = Paddle(PADDLE_XPOSITION)


ball = Ball()

pen = Pen()

def score_check():
    global score_A
    global score_B
    if ball.ball.xcor() < -340 and (paddle_a.paddle.ycor()-40 < ball.ball.ycor() < paddle_a.paddle.ycor()+40):
        ball.dx *= -1
        score_A += 1
        pen.pen.clear()
    if ball.ball.xcor() > 340 and (paddle_b.paddle.ycor()-40 < ball.ball.ycor() < paddle_b.paddle.ycor()+40):
        ball.dx *= -1
        score_B += 1
        pen.pen.clear()


while True:

    window.update()

    paddle_a.keyboard_control()
    paddle_b.keyboard_control()

    ball.move()
    ball.collision_check()

    pen.write()

    score_check()
