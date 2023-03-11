from PIL import Image
import json


fname = "image.h"


with open(fname, 'r') as f:
	data = f.read()



start = index = data.find("{") + 1
count = 1
while count > 0:
	if data[index] == "{":
		count += 1
	if data[index] == '}':
		count -= 1
	index += 1

v = data[start-1:index]
values = json.loads(v.replace('{','[').replace('}',']'))
print(values)
xranges = (
	min(values[0]),max(values[0])
)

yranges = (
	min(values[1]),max(values[1])
)

img = Image.new("RGB",(xranges[1]-xranges[0],yranges[1]-yranges[0]))
pix = img.load()










