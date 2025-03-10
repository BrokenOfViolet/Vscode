import requests
import re

url = "https://y.qq.com/n/ryqq/player"
headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
}

res = requests.get(url=url,headers=headers)
print(res.text)