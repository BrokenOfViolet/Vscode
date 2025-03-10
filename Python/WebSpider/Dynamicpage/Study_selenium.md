**This file is to study the python mould--selenium**  

+ find_element() series:用于定位单个的页面元素  
+ find_elements() series:用于定位一组页面元素，获取到的是一组列表
- - - -

1. 通过标签 id 定位  
```python
from selenium.webdriver.common.by import By
form selenium import webdriver
broswer = webdriver.Firefox()
input_text = broswer.find_element(By.ID, "the id of page element')
```

2. 通过标签 name 定位  
```
broswer.find_element(By.NAME, "the name")
```

3. 通过 class  
``` 
find_element(By.CLASS_NAME, "class name")
```

4. tag  
```
find_element(By.TAG_TAGNAME, 'xx')
```
- - - -

**dynamic operation**  
+ send messages or order:  
```python
input_text = broswer.find_element(By.ID, "srch")
input_text.send_keys("jar of love")     # 在搜索框中输入message
input_text.send_keys(Keys.RETURN)       # 模拟回车操作
```

+  clear()      -- 文本清空

+ submit()      -- 提交  
> attention: submit() 只能用于包含属性 type = 'submit' 的标签，并且嵌套在
> form 表单中。

- - - - 

**获取页面内容**

+ title             -- 页面标题
+ page_source       -- 页面源码
+ current_url       -- 页面链接
+ text              -- 标签内文本

+ 例如 : page_title = broswer.title

**页面操作**

+ forward()         -- 前进一页
+ back()            -- 后退一页
+ quit()            -- 关闭页面
+ refresh()         -- 页面刷新
