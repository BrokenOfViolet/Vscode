import time
from selenium import webdriver

browser = webdriver.Firefox()
browser.get("https://www.csdn.net/")
time.sleep(10)

browser.quit()