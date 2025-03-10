import requests


i = 2;
url = f"https://pic.netbian.com/index_{i}.html"
headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36'
}

res = requests.get(url,headers)

while res.status_code != 404:
    i += 1
    url = f"https://pic.netbian.com/index_{i}.html"
    res = requests.get(url,headers)
    print(i);

print("Totle pages:",i-1);

"""
Find the website had 1300 pages
2024.3.25
"""
