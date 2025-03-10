from pathlib import Path
import json


class Greet:
    def __init__(self, path=Path('/Users/mac/Desktop/folder/demo.json')):
        self.path = path

    def stored(self):
        try:
            number = input('type your favourate number:')
        except ValueError:
            print('please type the leagly number.')
        except FileNotFoundError:
            print('can not find the correct path')
        else:
            contents = json.dumps(number)
            self.path.write_text(contents)

    def answer(self):
        contents = self.path.read_text()
        number = json.loads(contents)
        print(f'I know your favourate number, it is {number}.')


one = Greet()
one.answer()