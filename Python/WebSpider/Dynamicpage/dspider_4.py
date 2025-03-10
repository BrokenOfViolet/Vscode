import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

broswer = webdriver.Firefox()
time.sleep(1)
broswer.get('https://music.163.com/')


input_text = broswer.find_element(By.ID, "srch")
input_text.send_keys("jar of love")
input_text.send_keys(Keys.RETURN)

time.sleep(5)

title = broswer.title
print(title)

source_code = broswer.page_source
with open('163music_code.txt', 'w+') as file:
    file.write(source_code)
print('Look in file.')

url = broswer.current_url
print(url)

time.sleep(3)

broswer.quit()