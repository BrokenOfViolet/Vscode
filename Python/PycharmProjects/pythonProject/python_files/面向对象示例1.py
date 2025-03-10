class Geese:
    neck = "脖子较长"
    wing = "振翅频率高"
    leg = "腿位于身体中心支点，行走自如"
    number = 0

    def __init__(self):
        Geese.number += 1
        print("\n我是第"+str(Geese.number)+"只大雁，我有以下特征：")
        print(Geese.neck)
        print(Geese.wing)
        print(Geese.leg)
        print("="*30, end="")


for i in range(4):
    wildGeese = Geese()
print("\n一共有"+str(Geese.number)+"只大雁.")
