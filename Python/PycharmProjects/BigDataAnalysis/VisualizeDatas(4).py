from pathlib import Path
import plotly.express as px
import pandas as pd
import json


path = Path('Datas/eq_data_30_day_m1.geojson')
try:
    contents = path.read_text()
except ValueError:
    contents = path.read_text(encoding='utf-8')
earthquake = json.loads(contents)

dicts = earthquake['features']
mags, titles, lons, lats = [], [], [], []
for eq_dict in dicts:
    mags.append(eq_dict['properties']['mag'])
    titles.append(eq_dict['properties']['title'])
    lons.append(eq_dict['geometry']['coordinates'][0])
    lats.append(eq_dict['geometry']['coordinates'][1])

data = pd.DataFrame(
    data=zip(lons, lats, titles, mags), columns=['经度', '纬度', '位置', '震级']
)
data.head()

fig = px.scatter(
    data,
    x='经度',
    y='纬度',
    range_x=[-200, 200],
    range_y=[-90, 90],
    width=800,
    height=800,
    size='震级',
    size_max=10,
    color='震级',
    hover_name='位置'
)
fig.write_html('global_earthquake.html')
fig.show()