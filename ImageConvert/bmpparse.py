from PIL import Image

image = Image.open('ImageConvert/test.bmp')
rgb_im =image.convert('RGB')

height = rgb_im.height
width = rgb_im.width



for x in range(width):
    for y in range(height):
        r, g, b = rgb_im.getpixel((x, y))
        print("x: " + str(x) + " y: " + str(y) + " red: " + str(r) + ", green: " + str(g) +", blue: " + str(b))

pass
