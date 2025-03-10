from bs4 import BeautifulSoup
import requests

url = "https://pic.netbian.com"
headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/17.0 Safari/605.1.15'
}

res = requests.get(url, headers)
res.encoding = "gbk"

soup = BeautifulSoup(res.text, "lxml")

# htmlPrettify = soup.prettify()
# print formated html page ( more comformatable )
# print(htmlPrettify)

links = soup.find_all('ul', class_="clearfix")

data = BeautifulSoup(str(links), 'lxml')

lis = data.find_all('li')
print(lis)