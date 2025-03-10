import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
# This expression is to avoid the interpreter raise an exception

home_url = "https://127.0.0.1/dvwa/"
path_number = 0
print("<--The path-->")
with open(r'common_web_filename', 'r', encoding='utf-8') as paths:
    for url_path in paths:
        new_url = home_url + url_path.strip('\n')
        res = requests.get(url=new_url, verify=False)
        if res.status_code != 404:
            print(f'Find the path--> {url_path}')
            path_number += 1
print(f'The totally number:{path_number}.')