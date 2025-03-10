import requests


url = "http://202.114.234.161/jsxsd/"
response = requests.get(url)

print(response.cookies)
print(response.status_code)
print(response.headers)
print(response.text)
