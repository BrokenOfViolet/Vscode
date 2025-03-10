import tkinter as tk
from tkinter import messagebox
from tkinter import Menu

class GUI:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("This is a window")
        self.root.geometry("800x600+400+150")

        self.menubar = Menu(self.root)
        self.root.config(menu=self.menubar)
        self.interface()
    
    def interface(self):
        self.menubar.add_cascade(label="文件", menu=self.papers())
        self.menubar.add_cascade(label="查看", menu=self.about())


        self.title = tk.Label(self.root, text='Login In')
        self.title.pack()

        self.username_label = tk.Label(self.root, text='Username')
        self.username_label.place(relx=0.2, rely = 0.1)
        self.password_label = tk.Label(self.root, text="Password")
        self.password_label.place(relx=0.2, rely=0.2)

        self.entry1 = tk.Entry(self.root)
        self.entry1.place(relx=0.4, rely=0.1)
        self.entry2 = tk.Entry(self.root)
        self.entry2.place(relx=0.4, rely=0.2)

        self.btn1 = tk.Button(self.root, text='Login', command=self.btn1_event)
        self.btn1.place(relx=0.3, rely=0.3)
        self.btn2 = tk.Button(self.root, text='Clear', command=self.btn2_event)
        self.btn2.place(relx=0.5, rely=0.3)

        self.text1 = tk.Text(self.root, width=80, height=10)
        self.text1.place(relx=0.1, rely=0.7)

    def btn1_event(self):
        self.username = self.entry1.get()
        self.password = self.entry2.get()

        if self.username == 'yan jiajun' and self.password == 'password':
            messagebox.showinfo("Attention", "Login sucess")
        else:
            messagebox.showinfo("Attention", "Login failed")
            self.btn2_event()
    
    def btn2_event(self):
        self.entry1.delete(0, tk.END)
        self.entry2.delete(0, tk.END)

    def papers(self):
        fmenu = Menu(self.menubar, tearoff=0)
        for item in ['新建','打开','保存','另存为']:
            fmenu.add_command(label=item)
        return fmenu
    
    def about(self):
        amenu = Menu(self.menubar, tearoff=0)
        for item in ['项目复选框','文件扩展名']:
            amenu.add_checkbutton(label=item)
        return amenu


if __name__ == '__main__':
    a = GUI()
    a.root.mainloop()