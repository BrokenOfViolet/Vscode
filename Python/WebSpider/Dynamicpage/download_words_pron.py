import requests

"""
This programme is aimed to spider the mp3 file.
The main url is <https://dict.youdao.com/dictvoice?audio=words&type=1>
>> 这是有道词典 <<
Analysis the url and then find the 'words' is the word you want.
'type' is the pronunciation you want. 1 for England(英式发音), 2 for American(美式发音).
"""

def return_type():
    type = int(input("Input the type of pronunciation(1 for England, other for America):"))
    if type == 1:
        return 1
    else:
        return 2

def download_mp3(word, word_type):
    headers = {
        'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36'
    }
    url = f"https://dict.youdao.com/dictvoice?audio={word}&type={word_type}"
    res = requests.get(url, headers)
    res.encoding = 'utf-8'
    with open(f'/Volumes/Earth/Sounds/WordProniciation/{word}.mp3', 'wb') as file:
        file.write(res.content)
    print(f"{word}.mp3 write sucessfully.")

word_type = return_type()
word = input("Input the words' pronunciation you want(press '*' to quit):\n")

while word != '*':
    download_mp3(word, word_type)
    word = input("Next word : ")

print("Over")
