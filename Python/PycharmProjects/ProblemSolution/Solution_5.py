import wordcloud
import matplotlib.pyplot as plt
import imageio.v2 as imageio
import jieba


mask = imageio.imread("material/picture.jpg")
file = open(r'material/praise.txt', 'r', encoding='utf-8')
text = file.read()
file.close()
ls = jieba.cut(text)
txt = ' '.join(ls)

stopwords = set()
content = [line.strip() for line in open(r'material/stopwords.txt', 'r', encoding='utf-8').readlines()]
stopwords.update(content)

w = wordcloud.WordCloud(font_path="/System/Library/Fonts/Supplemental/ADTNumeric.ttc", mask=mask, width=1000, height=700, background_color='white',
                        stopwords=stopwords)

w.generate(txt)
w.to_file("material/result.png")
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.imshow(w)
plt.axis('off')
plt.show()
