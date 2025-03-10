import turtle
import datetime
import wx


class MyFrame(wx.Frame):
    def __init__(self, parent):
        wx.Frame.__init__(self, parent, title="Enter you name", size=(600, 350), pos=(0.4, 0.2))
        panel = wx.Panel(self)
        self.title = wx.StaticText(panel, label="What's your name?", pos=(220, 40))
        self.name = wx.StaticText(panel, label="Name:", pos=(180, 80))
        self.name_bar = wx.TextCtrl(panel, pos=(230, 80), size=(200, 30), style=wx.TE_LEFT)
        self.bt_confirm = wx.Button(panel, label="Confirm", pos=(235, 150))
        self.bt_confirm.Bind(wx.EVT_BUTTON, self.OnClickConfirm)
        self.bt_cancel = wx.Button(panel, label="Cancel", pos=(335, 150))
        self.bt_cancel.Bind(wx.EVT_BUTTON, self.OnClickCancel)

    def OnClickConfirm(self, event):
        message = self.name_bar.GetValue()
        welcome = message + "\n" + "欢迎你！"

        Now = datetime.datetime.now()
        Now = Now.strftime("%Y-%m-%d %H:%M:%S")

        self.TurtlePaint(welcome, Nowtime=Now)
        wx.MessageBox(welcome)

    def OnClickCancel(self, event):
        self.name_bar.SetValue('')

    def TurtlePaint(self, name, Nowtime):
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


if __name__ == '__main__':
    app = wx.App()
    frame = MyFrame(parent=None)
    frame.Show()
    app.MainLoop()
