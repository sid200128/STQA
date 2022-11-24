from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

PATH = "C:\Program Files (x86)\chromedriver.exe"

driver = webdriver.Chrome(PATH)

driver.get("https://www.facebook.com/")
# print(driver.title)
email = driver.find_element("id", "email")
email.send_keys("test@gmail.com")
password = driver.find_element("id", "pass")
password.send_keys("1234")
password.send_keys(Keys.RETURN)
time.sleep(10)
driver.close()

