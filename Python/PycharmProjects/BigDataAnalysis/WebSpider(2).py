import requests
import re
import os


url = "https://pic.netbian.com"
headers = {
    "user-agent":
    "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36"
}
response = requests.get(url=url, headers=headers)
response.encoding = 'gbk'
content = response.text
pattern = re.compile('src="(.*?)" alt="(.*?)"')
images = re.findall(pattern=pattern, string=content)

path = r'WebImages'
if not path:
    os.mkdir(path)

for image in images:
    link = image[0]
    name = image[1]
    with open(path+'/{}.jpg'.format(name), "wb") as img:
        res = requests.get(url+link)
        img.write(res.content)
        img.close()
    print(f"{name}.jpg was got sucessfully!")
