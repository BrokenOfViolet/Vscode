from pathlib import Path
import json


path = Path('Datas/eq_data_30_day_m1.geojson')
contents = path.read_text()
earthquake = json.loads(contents)

path = Path('Datas/eq_data_30_day_m1.geojson')
readable = json.dumps(earthquake, indent=4)
path.write_text(readable)
