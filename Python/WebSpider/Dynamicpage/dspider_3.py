import requests

headers = {'User-Agent':
'Mozil/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36'}

res = requests.get("https://music.163.com/#/song?id=1995759563", headers=headers)
res.encoding = "utf-8"

with open ("163music.txt", "w+") as file:
    file.write(res.text)
print("write sucessfully.")