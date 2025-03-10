import requests

post_data = {'username':'admin', 'password':'password', 'Login':'Login'}
post_url = "https://127.0.0.1/dvwa/login.php"

session = requests.session()
res = requests.post(url=post_url, data=post_data, verify=False)
# The parameter <verify> means if checking the certificate of website
# set verify = False to ignore the check,or pycharm will report an error
security_data = {'security': 'low', 'seclev_sumbit': 'Submit', }
security_url = "https://localhost/dvwa/security.php"

session.post(url=security_url, data=security_data, verify=False)