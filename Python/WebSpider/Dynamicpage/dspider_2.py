from selenium import webdriver
import time

# 创建浏览器对象
driver = webdriver.Firefox()

# 打开音乐网站
driver.get("https://music.163.com/#/song?id=1995759563")

# 等待页面加载
time.sleep(3)

# 找到音乐播放按钮并点击
play_button = driver.find_element_by_xpath('/html/body/div[3]/div[1]/div/div/div[1]/div[1]/div[2]/div[2]/div/a[1]')
play_button.click()

# 等待音乐播放一段时间 
time.sleep(10)

# 关闭浏览器
driver.quit()
