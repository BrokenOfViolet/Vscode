from datetime import datetime
from pathlib import Path
import csv

import matplotlib.pyplot as plt

path = Path(r'WeatherData/sitka_weather_2021_full.csv')
lines = path.read_text().splitlines()
reader = csv.reader(lines)
lines = next(reader)
for index, name in enumerate(lines):
    print(index, name)
