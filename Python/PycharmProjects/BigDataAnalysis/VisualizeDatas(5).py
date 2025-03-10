import requests
import plotly.express as px

url = "https://api.github.com/search/repositories"
url += "?q=language:python+sort:stars+stars:>10000"

headers = {'Accept': 'application/vnd.github.v3+json'}

res = requests.get(url, headers=headers)
print(f'Satus code:{res.status_code}')

res_dict = res.json()
print(f"Total repositories:{res_dict['total_count']}")
print(f"Complete results:{not res_dict['incomplete_results']}")
items_dict = res_dict['items']

links, stars = [], []
hover_texts = []
for repository in items_dict:
    name = repository['name']
    url = repository['html_url']
    link = f"<a href='{url}>{name}</a>'"
    # Some problems happened here,Can not click text to access that webpage.Record it in 23-10-29
    links.append(link)

    stars.append(repository["stargazers_count"])

    owner = repository['owner']['login']
    description = repository['description']
    hover_text = f'{owner}<br>{description}'
    hover_texts.append(hover_text)


title = "Most-Starred Python Projetcts on Github"
labels = {'x': 'Repository', 'y': 'Stars'}
fig = px.bar(x=links, y=stars, title=title, labels=labels, hover_name=hover_texts)
fig.update_layout(title_font_size=24, xaxis_title_font_size=20, yaxis_title_font_size=20)
fig.update_traces(marker_color='SteelBlue', marker_opacity=0.6)
fig.write_html('DataSet/MostStarrtePyOnGh.html')
fig.show()


"""
import requests
import matplotlib.pyplot as plt

url = "https://api.github.com/search/repositories"
url += "?q=language:python+sort:stars+stars:>10000"

headers = {'Accept': 'application/vnd.github.v3+json'}

res = requests.get(url, headers=headers)
print(f'Satus code:{res.status_code}')

res_dict = res.json()
print(f"Total repositories:{res_dict['total_count']}")
print(f"Complete results:{not res_dict['incomplete_results']}")
items_dict = res_dict['items']

names, stars = [], []
hover_texts = []
for repository in items_dict:
    name = repository['name']
    names.append(name)

    stars.append(repository["stargazers_count"])

print(url)
title = "Most-Starred Python Projetcts on Github"
labels = {'x': 'Repository', 'y': 'Stars'}
plt.bar(x=names, height=stars)
plt.show()
"""