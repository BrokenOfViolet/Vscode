from selenium import webdriver
from selenium.webdriver.common.keys import Keys

# 初始化 Chrome 浏览器
driver = webdriver.Chrome()

# 打开网页
driver.get("https://y.qq.com/")

# 获取网络信息
logs = driver.get_log('driver')
for entry in logs:
    print(entry)

# 关闭浏览器
driver.quit()
