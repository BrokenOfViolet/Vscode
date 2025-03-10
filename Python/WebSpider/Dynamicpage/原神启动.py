import requests

url = "https://www.xfabe.com/YYDS/ys/"

headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36'
}

res = requests.get(url, headers)
res.encoding = 'utf-8'

print(res.text)