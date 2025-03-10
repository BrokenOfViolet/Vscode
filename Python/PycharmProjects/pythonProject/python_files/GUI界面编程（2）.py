import wx


class MyFrame(wx.Frame):
    def __init__(self, parent):
        wx.Frame.__init__(self, parent, title="Create class TextCtrl.", size=(800, 600), pos=(400, 200))
        panel = wx.Panel(self)
        self.title = wx.StaticText(panel, label="Please type username and password.", pos=(140, 20))
        self.username = wx.StaticText(panel, label="username:", pos=(50, 50))
        self.name_bar = wx.TextCtrl(panel, pos=(120, 50), size=(235, 25), style=wx.TE_LEFT)
        self.password = wx.StaticText(panel, label="password:", pos=(50, 90))
        self.pwd_bar  = wx.TextCtrl(panel, pos=(120, 90), size=(235, 25), style=wx.TE_PASSWORD)
        self.bt_confirm = wx.Button(panel, label="confirm", pos=(105, 130))
        self.bt_confirm.Bind(wx.EVT_BUTTON, self.OnclickSubmit)
        self.bt_cancel  = wx.Button(panel, label="cancel", pos=(195, 130))
        self.bt_cancel.Bind(wx.EVT_BUTTON, self.OnclickCancel)

    def OnclickSubmit(self, event):
        message = ""
        username = self.name_bar.GetValue()
        password = self.pwd_bar.GetValue()
        if username == "" or password == "":
            message = "用户名或密码不能为空！"
        elif username == "siri" and password == "0311":
            message = "登录成功！"
        else:
            message = "用户名或密码错误！"
        wx.MessageBox(message)

    def OnclickCancel(self, event):
        self.name_bar.SetValue("")
        self.pwd_bar.SetValue("")


if __name__ == '__main__':
    app = wx.App()
    frame = MyFrame(parent=None)
    frame.Show()
    app.MainLoop()