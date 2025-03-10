from pathlib import Path
import json


path = Path('/Users/mac/Desktop/folder/demo.json')
contents = path.read_text()
number = json.loads(contents)
