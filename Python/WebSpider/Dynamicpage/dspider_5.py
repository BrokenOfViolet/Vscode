from selenium import webdriver
import time

broswer = webdriver.Chrome(executable_path='/usr/local/bin/Google Chrome for Testing.app')

time.sleep(1)
broswer.quit()