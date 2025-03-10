import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dvwa/vulnerabilities/upload/"
files = {'upload':('test.png', open('test.png','rb'), 'image/png', {})}
params = {
    "MAX_FILE_SIZE":"100000",
    "uploaded":"",
    "Upload":"Upload"
}

cookies = dict(security='low', PHPSESSID='pgrh0qj243583p9jhk9ojbuk94')
res = requests.get(url=url, params=params, cookies=cookies, verify=False)
print(res.text)