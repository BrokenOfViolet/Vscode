import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dvwa/vulnerabilities/xss_r/"
cookies = dict(security='low', PHPSESSID='pgrh0qj243583p9jhk9ojbuk94')


print('<--The xss-->')
with open(r'xss_scripts', 'r', encoding='utf-8') as file:
    for xsser in file:
        payload = {
            "name":xsser.strip()
        }
        res = requests.get(url=url, params=payload, cookies=cookies, verify=False)
        if xsser not in res.text:
            print(f"Find xss --> {xsser}")