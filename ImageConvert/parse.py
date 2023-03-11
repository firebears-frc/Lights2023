from PIL import Image

OFFSET = (0,0)

t = Image.open('test.bmp')
t=t.resize((20,20))
b = t.getbbox()
pix = t.load()
xcoords = []
ycoords = []
rgb = [[],[],[]]
for y in range(b[3]):
	for x in range(b[2]):
		pixel = pix[x, y]
		if pixel != (0,0,0):
			xcoords.append(x)
			ycoords.append(y)
			rgb[0].append(pixel[0])
			rgb[1].append(pixel[1])
			rgb[2].append(pixel[2])
	
xstr = '{'+', '.join([str(x+OFFSET[0]) for x in xcoords])+'}'
ystr = '{'+', '.join([str(y+OFFSET[1]) for y in ycoords])+'}'
rgbstr = ''
for c in rgb:
	rgbstr += '{'+', '.join([str(v) for v in c])+'},\n'

rgbstr = rgbstr[:-2]


l = str(len(xcoords))

res = '#include <stdint.h>\n#define IMG_LEN '+l+'\nuint8_t thing[5]['+l+'] = {\n'
res += xstr
res += ',\n'
res += ystr
res += ',\n'
res += rgbstr
res += '\n};'
print(res)
t.show()
with open("image.h",'w') as f:
	f.write(res)


