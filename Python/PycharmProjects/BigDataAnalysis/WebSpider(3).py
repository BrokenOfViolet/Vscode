import requests
import re
from lxml import etree
import csv

url = "https://q.10jqka.com.cn/"
headers = {'User-Agent':
'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36'
}

response = requests.get(url=url, headers=headers)
response.encoding = 'GBK'
content = response.text
datas = re.findall('target="_blank">(\d.*)</a>', content)
numbers = re.findall('traget="_blank">()</a>', content)
for b in numbers:
    print(b)
for a in datas:
    print(a)