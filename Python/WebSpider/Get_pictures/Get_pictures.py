import requests
import re
import time
import random

class Spider:
    def __init__(self, top_url):
        self.top_url = top_url
        self.headers_list = ['Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36',
                             'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:86.0) Gecko/20100101 Firefox/86.0',
                             'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/14.0.3 Safari/605.1.15',
                             'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.190 Safari/537.36']
        self.headers = {'User-Agent':random.choice(self.headers_list)}
        self.Index_url = "https://pic.netbian.com/"
        
    def get_picture_url(self):
        res = requests.get(self.top_url, self.headers)
        res.encoding = 'gbk'
        result = re.findall(r'<a\s+href="([^"]+)"(?:\s+title="[^"]+")?\s+target="_blank', res.text)
        return result
    
    def get_picture_final_url(self, url):
        res = requests.get(url, self.headers)
        res.encoding = 'gbk'
        pic_attributes = re.findall(r'<img\s+src="([^"]+)"(?:\s+data-pic="[^"]+")?\s+alt="([^"]+)"',res.text)
        return pic_attributes[0] if pic_attributes else None
        
    def write_picture(self, file_url, file_name):
        res = requests.get(file_url, self.headers)
        res.encoding = "gbk"
        with open(f'/Volumes/Earth/Pictures/Images/{file_name}.jpg', 'wb') as file:
            file.write(res.content)
        print(f'{file_name} download sucessfully.')

    def write_all_pictures(self):
        result = self.get_picture_url()
        for pic_url in result:
            if pic_url.startswith("/"):
                full_link = self.Index_url + pic_url
                pic_attributes = self.get_picture_final_url(full_link)
                if pic_attributes:
                    final_full_link = self.Index_url + pic_attributes[0]
                    self.write_picture(final_full_link, pic_attributes[1])


Index_url = "https://pic.netbian.com/"

for i in range(400,501):
    try:
        top_url = Index_url + f'index_{i}.html'
        spider = Spider(top_url)
        spider.write_all_pictures()
        time.sleep(1)
    except Exception as e:
        print("Error", e)
    finally:
        print("Process End.")