import os

path = r'StaticWebPage/Images'
listnames = []
pathnames = []

for file in os.walk(path):
    for file_name in file[2]:
        label = f"""
    <div class="unit">
        <div class="img">
            <a href="../Images/{file_name}" target="_blank"/>
                <img src="../Images/{file_name}"/>
            </a>
        </div>
        <div class="desc">{file_name.rstrip('.jpg')}</div>
    </div>
"""
        print(label)