from datetime import datetime
from pathlib import Path
import csv

import matplotlib.pyplot as plt

path = Path(r'WeatherData/sitka_weather_2021_full.csv')
lines = path.read_text().splitlines()
reader = csv.reader(lines)
lines = next(reader)

aves = []
dates = []

time_pattern = '%Y-%m-%d'
for row in reader:
    current_time = datetime.strptime(row[2], time_pattern)
    try:
        ave = int(row[7]+row[8])/2
    except ValueError:
        print(f'Missing data in {current_time}.')
    else:
        dates.append(current_time)
        aves.append(ave)


plt.style.use('classic')
fig, ax = plt.subplots(figsize=(16, 9))
ax.plot(dates, aves, color='skyblue')
ax.set_title("Daily  Average Temperature In Sitka.\nYear 2021", fontsize=20)
ax.set_ylabel("Temperature (F)", fontsize=16)
ax.tick_params(labelsize=16)
fig.autofmt_xdate()
plt.show()