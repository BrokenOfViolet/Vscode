import requests
import re

url = "https://pic.netbian.com/tupian/33806.html"

res = requests.get(url)
res.encoding='gbk'

print(res)
link = re.findall(r'<img\s+src="([^"]+)"(?:\s+data-pic="[^"]+")?\s+alt="([^"]+)"', res.text)
print(link[0])
