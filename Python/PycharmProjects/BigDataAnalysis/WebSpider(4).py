import requests
import re
from lxml import etree


url = "http://localhost:63342/BigDataAnalysis/DataSetWeb.html?_ijt=994rcd77u5oq3pjnpon2hmi330&_ij_reload=RELOAD_ON_SAVE"
response = requests.get(url)
content = response.text
spider = re.findall(r'<td>(.*?)</td>', content)
name = []
number = []
for value in spider:
    if type(value) == "<class 'str'>":
        name.append(value)
    else:
        number.append(value)
print(name)
print(number)
# page = etree.HTML(content)
# element = page.xpath('')