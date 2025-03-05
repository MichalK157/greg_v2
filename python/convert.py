import cv2
import numpy as np

file = cv2.imread("test.jpg",cv2.COLOR_BGR2RGB)
im = file.copy()
R5 = (im[...,0]>>3).astype(np.uint16) << 11
G6 = (im[...,1]>>2).astype(np.uint16) << 5
B5 = (im[...,2]>>3).astype(np.uint16)

# Assemble components into RGB565 uint16 image
RGB565 = R5 & G6 & B5
print(RGB565.shape)

cv2.imwrite("test565.jpeg", RGB565)

hight,wide,d = file.shape

R= (file[...,0]>>3).astype(np.uint32) << 16
G = (file[...,1]>>2).astype(np.uint32) << 8
B = (file[...,2]>>3).astype(np.uint32)



RGB = R | G | B

hight,wide = RGB.shape
with open("RGB_out","w")as rg:
    for h in range(hight):
        for w in range(wide):
            rg.write(f"{hex(RGB[h][w])}, ")
        rg.write("\n")