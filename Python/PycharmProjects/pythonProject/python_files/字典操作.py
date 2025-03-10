geography = {'the yantze river': 'china', 'the nile': 'egypt', 'the amazon river': 'amazon'}
count = 0
for river, country in geography.items():
    print(f'{river.title()} runs through {country.title()}.')

print('')
print('Here are all rivers mentioned:', end='')
for river in geography.keys():
    count = count + 1
    print(f'{river}', end='')
print(f'\nthere are {count} rivers in total.')

print('')
list_country = ['Russia', 'China', 'America']
copy = []
for i in range(len(list_country)):
    item = list_country[i].lower()
    copy.append(item)
for country in geography.values():
    if country in copy:
        print(f'{country} had already been included.')
    else:
        print(f'{country} had not been included.')