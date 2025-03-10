import requests


payload = {'key1': 'value1', 'key2': 'value2'}
response = requests.get('http://httpbin.org/get', params=payload)
print(response.content)
print(response.text)