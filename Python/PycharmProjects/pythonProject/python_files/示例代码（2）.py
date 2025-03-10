from pathlib import Path


path = Path('/Users/mac/Desktop/folder/pysite.txt')
content = ''
while True:
    string = input("type the words you want(press 'q' to quit):")
    if string != 'q':
        content = content+string+'\n'
    else:
        print('The program is paused Now.')
        break
    path.write_text(content)
