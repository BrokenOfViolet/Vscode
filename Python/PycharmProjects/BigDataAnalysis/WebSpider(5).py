import requests
import time
import re
import os

base_url = "https://pic.netbian.com"
res = requests.get(url=base_url)
res.encoding = res.apparent_encoding
content = res.text

def detect(url, name, path):
    res_new = requests.get(url=url)
    res_new.encoding = res_new.apparent_encoding
    content_new = res_new.text
    url_new = re.findall('<img src="(.*?)" data-pic=', content_new)
    with open(f'{path}/{name}.jpg', 'wb') as img:
        res_new = requests.get(url=base_url + url_new[0])
        img.write(res_new.content)
        img.close()
    print(f"{name}.jpg was got sucessfully.")


urls = []
names = []

hrefs = re.findall('href="(.*?)" title="(.*?)" target="_blank"', content)[2:-2]
for i in hrefs:
    urls.append(base_url+i[0])
    names.append(i[1])

path = 'NewImages'
if not os.path.exists(path):
    os.mkdir(path)

for index in range(len(hrefs)):
    detect(urls[index], names[index], path)
    time.sleep(1)


# 批量爬取壁纸图片2023-12-6
# 本来可以直接获取首页图片的URL，但是这样爬出来的图片清晰度不是很高，所以我
# 获取点击图片后的跳转链接，然后在获取图片的链接，此时图片的清晰度更高
# 它这个网站以前获取的链接是绝对地址（https类型的），后来变成了相对地址（文件夹类型的），见WebSpider(2)
#