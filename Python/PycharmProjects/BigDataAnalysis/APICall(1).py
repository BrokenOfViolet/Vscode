import requests

url = "https://api.github.com/search/repositories"
url += "?q=language:python+sort:stars+stars:>10000"

headers = {'Accept': 'application/vnd.github.v3+json'}

res = requests.get(url, headers=headers)
print(f'Satus code:{res.status_code}')

res_dict = res.json()
print(f"Total repositories:{res_dict['total_count']}")
print(f"Complete results:{not res_dict['incomplete_results']}")
items_dict = res_dict['items']
print(f'\nValues:{len(items_dict)}')

item_dict = items_dict[0]
print(f"\nValue keys:{len(item_dict)}")
for key in sorted(item_dict.keys()):
    print(key)