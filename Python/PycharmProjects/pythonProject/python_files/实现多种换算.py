print("-"*30+"\n")
print("1.根据父母的身高预测儿子的身高。\n"
      "2.根据总步数计算消耗的热量值。\n"
      "3.将摄氏温度转换为华氏温度。\n")
option = int(input("请输入选项前的数字:\n"))

while option == 1:
    judge = input("请输入(输入break退出):")
    if judge == 'break':
        print("已退出\n")
        break
    else:
        father = float(input("请输入父亲的身高:\n"))
        mother = float(input("请输入母亲的身高:\n"))
        son = (father + mother) * 0.54
        print("预测儿子的身高:\n" + str(son))
        print("预测结束，输入break退出。")

while option == 2:
    pace = float(input("请输入当天行走的步数！\n"))
    calorie = pace*28
    print("今天共消耗卡路里："+str(calorie)+"(即"+str(calorie/100)+"千卡）")
    break

while option == 3:
    pass
