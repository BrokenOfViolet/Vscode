import random


class Die:
    def __init__(self, sides, name):
        self.sides = sides
        self.name = name

    def roll_side(self):
        random_number = random.randint(1, 6)
        print(f'The die {self.name}\'s number on die is {random_number}.')

    def describe(self):
        print(f'The sides number of die is {self.sides},', end='')
        print(f'and the name of die is {self.name}.\n')


die = Die(6, 'siri')
die.describe()
for i in range(3):
    die.roll_side()