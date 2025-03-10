spector = str(input())

num = int(input())

year = str(input())
suffix = ['年','月','日']
print(spector*num)
for i in range(3):
    print(year.split('/')[i]+suffix[i], end='')
print()
print(spector*num)
