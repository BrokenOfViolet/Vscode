from bs4 import BeautifulSoup

# HTML 内容（可以是从网页获取的内容）
html_doc = '''
<html>
<head>
    <title>示例页面</title>
</head>
<body>
    <h1>这是一个示例页面</h1>
    <p class="content">这是一个段落。</p>
    <ul>
        <li>项目 1</li>
        <li>项目 2</li>
        <li>项目 3</li>
    </ul>
</body>
</html>
'''

# 创建 BeautifulSoup 对象并指定解析器（这里使用内置的解析器 html.parser）
soup = BeautifulSoup(html_doc, 'html.parser')

# 通过标签名获取元素
h1_tag = soup.h1
print("h1 标签内容:", h1_tag.text)  # 输出：这是一个示例页面

# 通过类名获取元素
p_tag = soup.find('p', class_='content')
print("p 标签内容:", p_tag.text)  # 输出：这是一个段落。

# 通过标签名获取所有元素
list_items = soup.find_all('li')
print("ul 中的项目列表:")
for item in list_items:
    print(item.text)
