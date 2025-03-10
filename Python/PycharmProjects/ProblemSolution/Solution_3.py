# （1）给定两个日期，判断两日期相隔多少天（4 分）
# （2）给定一个日期，一个正整数 n，判断 n 天前的日期（3 分）
# （3）给定一个日期，一个正整数 n，判断 n 天后的日期（3 分）

choice = 1
months = [31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31]


def calculate(strlist):
    month = int(strlist[1])
    day = int(strlist[2])
    numbers_of_days = sum(months[:month-1]) + day
    return numbers_of_days


def compute(days, list_date):
    month, day = 0, 0
    years = days // 365
    remainder = days % 365
    year_new = int(list_date[0]) + years
    for i in range(1, len(months)):
        if remainder > months[i]:
            month = month + 1
            remainder = remainder - months[i]
        else:
            day = remainder
    result = f'结果是{year_new}年{month+1}月{day}日'
    return result


def solution1():
    date1 = input("请输入起始年月日，数字间用空格隔开：")
    date2 = input("请输入终止年月日，数字间用空格隔开：")
    list_date1 = list(date1.split())
    list_date2 = list(date2.split())

    days1 = calculate(list_date1)
    days2 = calculate(list_date2)

    leap = 0
    for a in range(int(list_date1[0]), int(list_date2[0])+1):
        if a % 4 == 0 and int(list_date2[1]) >= 3:
            leap = leap + 1
    result = (int(list_date2[0])-int(list_date1[0])) * 365 + leap + (days2-days1)
    print(result)


def solution2():
    date = input("请输入结束年月日，数字间用空格隔开：")
    add = -int(input("请输入天数："))
    list_date = list(date.split())
    days = calculate(list_date)
    days = days + add
    result = compute(days=days, list_date=list_date)
    print(result)


def solution3():
    date = input("请输入开始年月日，数字间用空格隔开：")
    add = int(input("请输入天数："))
    list_date = list(date.split())
    days = calculate(list_date)
    days = days + add
    result = compute(days=days, list_date=list_date)
    print(result)


while choice != 0:
    try:
        choice = int(input("想要实现题目中的要求几？").strip())
    except:
        print("请不要输入数字以外的字符！")
    else:
        if choice == 1:
            solution1()
        elif choice == 2:
            solution2()
        elif choice == 3:
            solution3()
        else:
            continue
