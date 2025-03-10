from selenium import webdriver
from browsermobproxy import Server

# 启动BrowserMob Proxy服务器
server = Server("/usr/local/bin/browsermob-proxy")
server.start()
proxy = server.create_proxy()

# 设置Firefox WebDriver使用代理
proxy_address = proxy.proxy
options = webdriver.FirefoxOptions()
options.add_argument('--proxy-server=%s' % proxy_address)
driver = webdriver.Firefox(options=options)

# 开始捕获网络流量
proxy.new_har("firefox")

# 打开网页
driver.get("https://www.youdao.com/result?word=planetary&lang=en")

# 捕获网络请求和响应
entries = proxy.har['log']['entries']
for entry in entries:
    request = entry['request']
    response = entry['response']
    print("Request URL:", request['url'])
    print("Response Status:", response['status'])

# 关闭浏览器和代理服务器
driver.quit()
server.stop()

# This programme is falied.I don't know why.
# Error Here > browsermobproxy.exceptions.ProxyServerError: Can't connect to Browsermob-Proxy