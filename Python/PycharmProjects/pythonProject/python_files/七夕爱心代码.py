import time
import wx
import random
from math import sin, cos, pi, log
from tkinter import *


def WordLove(self):
    words = "love"
    print('\n')
    for item in words.split():
        letterlist = []
        for y in range(12, -12, -1):
            list_X = []
            letters = ''
            for x in range(-30, 30):
                expression = ((x * 0.05) ** 2 + (y * 0.1) ** 2 - 1) ** 3 - (x * 0.05) ** 2 * (y * 0.1) ** 3
                if expression <= 0:
                    letters += item[(x - y) % len(item)]
                else:
                    letters += ' '
            list_X.append(letters)
            letterlist += list_X
        print('\n'.join(letterlist))
        time.sleep(0.5)
    print('\n                                           to 茂茂酱！！\n\n')


def PaintLove(self):
    CANVAS_WIDTH = 640
    CANVAS_HEIGHT = 480
    CANVAS_CENTER_X = CANVAS_WIDTH / 2
    CANVAS_CENTER_Y = CANVAS_HEIGHT / 2
    IMAGE_ENLARGE = 11
    HEART_COLOR = "#FFC0CB"  # ff2121

    def heart_function(t, shrink_ratio: float = IMAGE_ENLARGE):

        x = 16 * (sin(t) ** 3)
        y = -(13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t))

        x *= shrink_ratio
        y *= shrink_ratio

        x += CANVAS_CENTER_X
        y += CANVAS_CENTER_Y

        return int(x), int(y)

    def scatter_inside(x, y, beta=0.15):

        ratio_x = - beta * log(random.random())
        ratio_y = - beta * log(random.random())

        dx = ratio_x * (x - CANVAS_CENTER_X)
        dy = ratio_y * (y - CANVAS_CENTER_Y)

        return x - dx, y - dy

    def shrink(x, y, ratio):

        force = -1 / (((x - CANVAS_CENTER_X) ** 2 + (y - CANVAS_CENTER_Y) ** 2) ** 0.6)  # 这个参数...
        dx = ratio * force * (x - CANVAS_CENTER_X)
        dy = ratio * force * (y - CANVAS_CENTER_Y)
        return x - dx, y - dy

    def curve(p):

        return 2 * (2 * sin(4 * p)) / (2 * pi)

    class Heart:

        def __init__(self, generate_frame=20):
            self._points = set()  # 原始爱心坐标集合
            self._edge_diffusion_points = set()  # 边缘扩散效果点坐标集合
            self._center_diffusion_points = set()  # 中心扩散效果点坐标集合
            self.all_points = {}  # 每帧动态点坐标
            self.build(2000)

            self.random_halo = 1000

            self.generate_frame = generate_frame
            for frame in range(generate_frame):
                self.calc(frame)

        def build(self, number):

            for _ in range(number):
                t = random.uniform(0, 2 * pi)
                x, y = heart_function(t)
                self._points.add((x, y))

            for _x, _y in list(self._points):
                for _ in range(3):
                    x, y = scatter_inside(_x, _y, 0.05)
                    self._edge_diffusion_points.add((x, y))

            point_list = list(self._points)
            for _ in range(4000):
                x, y = random.choice(point_list)
                x, y = scatter_inside(x, y, 0.17)
                self._center_diffusion_points.add((x, y))

        @staticmethod
        def calc_position(x, y, ratio):

            force = 1 / (((x - CANVAS_CENTER_X) ** 2 + (y - CANVAS_CENTER_Y) ** 2) ** 0.520)  # 魔法参数

            dx = ratio * force * (x - CANVAS_CENTER_X) + random.randint(-1, 1)
            dy = ratio * force * (y - CANVAS_CENTER_Y) + random.randint(-1, 1)

            return x - dx, y - dy

        def calc(self, generate_frame):
            ratio = 10 * curve(generate_frame / 10 * pi)  # 圆滑的周期的缩放比例

            halo_radius = int(4 + 6 * (1 + curve(generate_frame / 10 * pi)))
            halo_number = int(3000 + 4000 * abs(curve(generate_frame / 10 * pi) ** 2))

            all_points = []

            heart_halo_point = set()
            for _ in range(halo_number):
                t = random.uniform(0, 2 * pi)
                x, y = heart_function(t, shrink_ratio=11.6)
                x, y = shrink(x, y, halo_radius)
                if (x, y) not in heart_halo_point:
                    heart_halo_point.add((x, y))
                    x += random.randint(-14, 14)
                    y += random.randint(-14, 14)
                    size = random.choice((1, 2, 2))
                    all_points.append((x, y, size))

            for x, y in self._points:
                x, y = self.calc_position(x, y, ratio)
                size = random.randint(1, 3)
                all_points.append((x, y, size))

            for x, y in self._edge_diffusion_points:
                x, y = self.calc_position(x, y, ratio)
                size = random.randint(1, 2)
                all_points.append((x, y, size))

            for x, y in self._center_diffusion_points:
                x, y = self.calc_position(x, y, ratio)
                size = random.randint(1, 2)
                all_points.append((x, y, size))

            self.all_points[generate_frame] = all_points

        def render(self, render_canvas, render_frame):
            for x, y, size in self.all_points[render_frame % self.generate_frame]:
                render_canvas.create_rectangle(x, y, x + size, y + size, width=0, fill=HEART_COLOR)

    def draw(main: Tk, render_canvas: Canvas, render_heart: Heart, render_frame=0):
        render_canvas.delete('all')
        render_heart.render(render_canvas, render_frame)
        main.after(160, draw, main, render_canvas, render_heart, render_frame + 1)

    if __name__ == '__main__':
        root = Tk()
        canvas = Canvas(root, bg='black', height=CANVAS_HEIGHT, width=CANVAS_WIDTH)
        canvas.pack()
        heart = Heart()
        draw(root, canvas, heart)
        root.mainloop()


def love(self):
    import turtle

    canvas = turtle.Screen()
    pen = turtle.Turtle()

    pen.color('red')
    pen.pensize(3)
    pen.speed(5)

    pen.up()
    pen.goto(0, -100)
    pen.down()

    pen.begin_fill()
    pen.left(45)
    pen.forward(150)
    pen.circle(75, 180)
    pen.right(90)
    pen.circle(75, 180)
    pen.forward(150)
    pen.end_fill()

    pen.hideturtle()
    turtle.done()


def OtherLove(self):
    import turtle
    turtle.color('red')
    turtle.write("I love you")


class MyFrame(wx.Frame):
    def __init__(self, parent):
        wx.Frame.__init__(self, parent, title="Create class TextCtrl.", size=(800, 600), pos=(400, 200))
        panel = wx.Panel(self)
        self.title = wx.StaticText(panel, label="Please type the password.", pos=(250, 20))
        self.username = wx.StaticText(panel, label="Password:", pos=(100, 70))
        self.name_bar = wx.TextCtrl(panel, pos=(200, 70), size=(235, 25), style=wx.TE_LEFT)
        self.bt_confirm = wx.Button(panel, label="confirm", pos=(105, 130))
        self.bt_confirm.Bind(wx.EVT_BUTTON, self.OnclickSubmit)
        self.bt_cancel  = wx.Button(panel, label="cancel", pos=(195, 130))
        self.bt_cancel.Bind(wx.EVT_BUTTON, self.OnclickCancel)

    def OnclickSubmit(self, event):
        message = ""
        username = self.name_bar.GetValue()
        if username == "":
            message = "用户名或密码不能为空！"
        elif username == "苏灵杰":
            message = "登录成功！"
            PaintLove(self)
        elif username == "洛文豪":
            love(self)
        elif username == "曹辽":
            WordLove(self)
        elif username == "严佳均":
            OtherLove(self)
        else:
            message = "The password you type can't be found！"
        wx.MessageBox(message)

    def OnclickCancel(self, event):
        self.name_bar.SetValue("")


if __name__ == '__main__':
    app = wx.App()
    frame = MyFrame(parent=None)
    frame.Show()
    app.MainLoop()
