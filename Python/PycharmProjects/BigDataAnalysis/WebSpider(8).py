# multiple pages scratch
# still use regular expression

import requests
import re


def detect(index, name_list):
    home_url = 'https://ssr1.scrape.center/page/' + str(index)
    headers = {}
    response = requests.get(url=home_url)
    response.encoding = 'utf-8'
    content = response.text
    movie_name = re.findall('class="m-b-sm">(.*?)</h2>', content)
    name_list.append(movie_name)


movie_list = []

for i in range(1, 11):
    detect(i, movie_list)

for block in movie_list:
    with open(r'SpiderSet/TextContent/movie_rank.txt', 'a+') as file:
        for movie in block:
            file.write(movie)
            file.write('\n')
        file.close()