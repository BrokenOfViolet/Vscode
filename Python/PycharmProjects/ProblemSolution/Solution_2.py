# 相信大家背过九九乘法表，那大家有没有听过印度的十九十九乘法表呢，余华杰哥哥据
# 此又想出来了一个好玩的问题：
# 为什么乘法表一定要是以九为结尾的呢，为什么乘法表一定是是十进制的呢，为什么世
# 界上还有乘法这种东西呢？于是带着疑问，余华杰哥哥利用 c++ 开发出了 n 进制乘法表和
# 十进制 n*m 乘法表。张汝坤听到这件事后，兴致冲冲过来看热闹，表示你这代码不行啊，我
# 用 python 几行就能搞定。那么聪明的你，可以用几行来解决这个问题呢？
# 请利用 python 代码实现，给定两个正整数 n、m，两个数字用空格隔开，输出 n 行 m
# 列十进制乘法表（若 m>n，则输出 m 行 n 列十进制乘法表）2，答案输出示例如图二

twonumber = input("Input two numbers:")
numlist = twonumber.split()

m = int(numlist[0])
n = int(numlist[1])

rows = m if m > n else n
columns = n if n < m else m
for row in range(1, rows+1):
    for column in range(1, row+1):
        if column <= columns:
            print(f"{column} * {row} = {row*column}\t", end='')
    print('')