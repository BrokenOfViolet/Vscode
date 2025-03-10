import requests

url = "https://m10.music.126.net/20240319230609/0c78f9aca1a8975072154d3c66d7d210/ymusic/565b/0159/5309/a1695534bc63c6de4f61dcf0d98dae72.mp3"

res = requests.get(url)
res.encoding = "utf-8"

try:
    with open("/Users/mac/Capcut/Audios/IndentityV.mp3", "wb") as file:
        file.write(res.content)
except:
    print("Something error happened.")
print("Successfully run.")
