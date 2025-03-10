import requests


url = input("please enter the url of the song:\n")
headers = {'User-Agent':
           'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36'}
res = requests.get(url, headers)
res.encoding = "utf-8"

song_name = input("enter the name of the song:")
path = '/Users/mac/Capcut/Audios/' + song_name + '.mp3'
with open(path, 'wb') as file:
    file.write(res.content)
print(f"File {song_name}.mp3 Download Sucessfully.")


"""
the process of acquiring the url of the song:
1. click the music website (like 'QQ音乐', '酷狗音乐', '网易云音乐')
2. search the name of the song in the search box
3. goto the page and right-click then, click 'check'
4. choose 'NetWork' on the menu and sort this file by size ( commomly the max size file is mp3 file.)  
--------- The set of procession seems none-automated, and I will write another codes.
"""