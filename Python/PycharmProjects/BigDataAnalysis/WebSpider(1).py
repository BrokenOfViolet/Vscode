import requests
import re


url = "https://pvp.qq.com/web201605/wallpaper.shtml###"
headers = {
    "user-agent":
    "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36"
}

response = requests.get(url=url, headers=headers)
response.encoding = response.apparent_encoding
content = response.text
links = re.findall('src="(.*?)">', content)
for a in links:
    print(a)


# This web can't use the traditional method to crawl datas.
# the picture you want to load must be clickd(bind the event),so the url of each image can not easily get.