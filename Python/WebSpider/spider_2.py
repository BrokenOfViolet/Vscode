import requests

url = "https://dl.stream.qqmusic.qq.com/C400000tGFPi4U6S58.m4a?guid=4679241390&vkey=43ED384B1693B879A541CF3EFAED3DF8829A0F636135414DC393A7F255ED259E6B89B2B9A568AC995EF2B796BD9B58F4F0A7ACA44779C52D&uin=3330622952&fromtag=120032"
headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
}

res = requests.get(url=url, headers=headers)
res.encoding = 'utf-8'

with open('exam.mp3', 'wb') as file:
    file.write(res.content)
    file.close()
