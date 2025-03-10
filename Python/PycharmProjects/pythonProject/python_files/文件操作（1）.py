with open(r'/Users/mac/Desktop/folder/file(1).txt', 'r') as file:
    message = file.read()
    print(type(message))
    print(message)
    file.close()
print("="*20)

'''下面代码的作用是逐行读取文件内容'''
with open(r'/Users/mac/Desktop/folder/file(1).txt', 'r') as file:
    number = 0
    while True:
        number += 1
        txt = file.readline()
        if txt == '':
            break
        print(number, txt, end="\n")
    file.close()
