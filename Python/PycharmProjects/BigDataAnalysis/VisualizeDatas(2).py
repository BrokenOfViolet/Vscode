from pathlib import Path
from datetime import datetime
import csv

import matplotlib.pyplot as plt

path = Path(r'WeatherData/sitka_weather_2021_full.csv')
lines = path.read_text().splitlines()
reader = csv.reader(lines)
header_row = next(reader)
highs = []
lows = []
dates = []
for row in reader:
    current_date = datetime.strptime(row[2], '%Y-%m-%d')
    try:
        high = int(row[7])
        low = int(row[8])
    except ValueError:
        print(f'Missing data for {current_date}.')
    else:
        dates.append(current_date)
        highs.append(high)
        lows.append(low)


plt.style.use('classic')
fig, ax = plt.subplots(figsize=(16, 9))
ax.plot(dates, highs, color='red')
ax.plot(dates, lows, color='blue')
ax.fill_between(dates, highs, lows, facecolor='blue', alpha=0.1)
title = "Daily high and low temperatures, 2021\nDeath valley, CA".title()
ax.set_title(title, fontsize=20)
ax.set_xlabel('', fontsize=16)
fig.autofmt_xdate()
ax.set_ylabel('Temperature (F)', fontsize=16)
ax.tick_params(labelsize=16)

plt.show()