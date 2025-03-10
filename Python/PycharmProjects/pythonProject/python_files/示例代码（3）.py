from pathlib import Path


def read_file(file_name):
    """the name of the file you want to read,
    must contain the contact pathof the file"""
    path = Path(file_name)
    try:
        content = path.read_text()
    except FileNotFoundError:
        print('Can not find the file.')
    else:
        print(content)
        print(type(content))


read_file('/Users/mac/Desktop/folder/pysite.txt')
read_file('1')