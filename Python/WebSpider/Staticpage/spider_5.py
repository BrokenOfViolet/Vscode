import requests
 
url = "http://www.cip.cc/"
 
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36'
}
 
proxy = {
    "http": "c612.kdltps.com:15818"
}
 
r = requests.get(url=url, headers=headers, proxies=proxy)
r.encoding = "utf-8"
print(r.status_code)
print(r.text)
with open('proxy.html', 'w', encoding='utf-8') as fp:
    fp.write(r.text)