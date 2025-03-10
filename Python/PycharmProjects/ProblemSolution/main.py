number = 1

while number <= 10:
    with open(r'Solution_'+str(number)+'.py', 'w') as file:
        file.close()
    number = number + 1