# 这天余华杰哥哥想出一个好玩的问题:
# 给定两个正整数 n、m, 将 m 所有位上的数字加和，并判断其是否为 n 的倍数。一番思
# 索后，他决定拿斐波那契数列开刀。几下功夫，余华杰哥哥就实现了，给定一个正整数 n, 判
# 断斐波那契数列的前 100 项中有多少项符合所有位上的数字加和为 n 的整数倍，并将符合条
# 件的项打印出来。但余华杰哥哥虽然 c++ 写的贼六，却不会写 python，于是他想，正好借
# 机考验一下新人，快来用 python 帮他实现吧！
# 现在请写出函数进行实现，其中 n 为用户自己输入，m 为斐波那契数列的前 100 项，在
# 100 个数字中，将符合要求的数字打印出来，并说明它是第几项。


Fsequence = [1, 1, 2]

for i in range(0, 97):
    Fsequence[i+2] = Fsequence[i+1] + Fsequence[i]
    Fsequence.append(Fsequence[i])

number = int(input("请输入数字：\n"))

newlist = []
for value in Fsequence:
    result = 0
    for digit in str(value):
        result += int(digit)
    newlist.append(result)

i = 0
for new in newlist:
    if new % number == 0:
        print(f"第{i}项：\t{Fsequence[i]}\\")
    i = i + 1
