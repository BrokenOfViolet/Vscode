import requests
import re

url = "https://www.kugou.com/mixsong/22mehb22.html?fromsearch=love%20story#"
headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
}

res = requests.get(url=url, headers=headers)
finds = re.findall('src="(.*?).mp3"', res.text)
print(finds)
print(res.text)