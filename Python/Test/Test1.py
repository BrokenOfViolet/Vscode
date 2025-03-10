import requests
from bs4 import BeautifulSoup
import xlsxwriter


url = "https://jwxt.zuel.edu.cn/jsxsd/pyfa/pyfa_query"
headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36'
}
cookies = {
    'Hm_lvt_5320013b20652def1496e4f154f179fa':'1702537002',
    'SERVERID_gld':'gld02',
    'SERVERID_jsxsd':'jsxsd3',
    'bzb_jsxsd':'E2FA0C04D36F14381FF7A012E88B4443',
    'bzb_njw':'2A162F789B232A5A85929F91878DBB8E',
    }

res = requests.get(url=url,headers=headers,cookies=cookies)
res.encoding = 'utf-8'

workbook = xlsxwriter.Workbook('培养方案.xlsx')
worksheet = workbook.add_worksheet('sheet1')

soup = BeautifulSoup(res.text, 'lxml')

ths = soup.find_all('th', attrs={'class':'Nsb_r_list_thb'})

row_index = 0
columns = len(ths)

for index, td in enumerate(ths):
    worksheet.write(0,index,td.text)
    
tds = soup.find_all('td')

row_lists = []
row_list = []
for column_index, td in enumerate(tds):
    if column_index % columns != 0:
        row_list.append(td.text)
    else:
        row_list.append(td.text)
        row_lists.append(row_list)

for row_num, row_data in enumerate(row_lists):
    for col_num, col_data in enumerate(row_data):
        worksheet.write(row_num+1, col_num, col_data)

workbook.close()