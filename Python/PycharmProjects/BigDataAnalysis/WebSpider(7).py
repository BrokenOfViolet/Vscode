import requests
import time
import re
import os


url = "https://huaban.com/boards/85559748"
headers = {
    "User-Agent":
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36"
}

response = requests.get(url=url, headers=headers)
response.encoding = 'utf-8'
content = response.text

pattern = re.compile('alt="(.*?) src="(.*?)"')
images = re.findall(pattern,content)
images = images[4:-1]

print(len(images))

names = []
links = []

for tup in images:
    name = tup[0].split('"', 1)[0]
    names.append(name)
    link = tup[1].replace("240webp","1200png")
    links.append(link)

path = r'CherryGirls'
if not path:
    os.mkdir(path)

for i in range(len(images)):
    with open(f'{path}/{i}.png', 'wb') as img:
        res = requests.get(links[i])
        img.write(res.content)
        time.sleep(1)
        img.close()
    print(f'{names[i]}.png was got sucessfully!')


# 爬取八重神子的图片，常规获取的的URL尾部为200webp，此时文件类型为webp，分辨率为200（webp类型的文件不能做壁纸，也无法直接预览）
# 我发现尾部改为1200png时，可以获取分辨率为1200的png文件，简直amazing，我简直是个天才！
# 这个网站有时候出现的是html页面，有时候是javascript代码，有时候为空，可能是反爬机制的问题吧
# 爬取于2023-12-5
