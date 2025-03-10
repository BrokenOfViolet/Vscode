import requests


data = {'word': '临澧一中严佳均'}

for number in range(1000):
    number = number+1
    response = requests.post('http://www.baidu.com', data=data)
print("完成一百次请求")
