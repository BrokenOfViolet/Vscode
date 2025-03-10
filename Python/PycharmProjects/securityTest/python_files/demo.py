def classfy():
    number = int(input("请输入您的分数:"))
    if 90<=number<=100:
        print("A")
    elif 80<=number<=89:
        print("B")
    elif 70<=number<=79:
        print("C")
    elif 60<=number<=69:
        print("D")
    else:
        print("E")
classfy()