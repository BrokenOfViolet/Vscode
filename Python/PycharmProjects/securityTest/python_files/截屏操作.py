from PIL import ImageGrab
import time


interval = 4
time.sleep(interval)
image = ImageGrab.grab()
image.show()

"""
image = ImageGrab.grabclipboard()
if isinstance(image, Image.Image):
    im.save(file_path)
else:
    print("clipboard is empty.")
"""