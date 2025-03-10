string = input("please input a number:")
isNumber = 1
for i in range(0, int(len(string)/2)):
    if string[i] != string[len(string)-i-1]:
        isNumber = 0
if isNumber == 1:
    print("Yse")
else:
    print("No")