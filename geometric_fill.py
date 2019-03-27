# -*- coding: utf-8 -*-
"""
Created on Sun Feb 24 09:24:13 2019

@author: aakas
"""
import numpy as np
from matplotlib import pyplot as plt
from math import sin, cos, atan2, pi, ceil, sqrt

with open("resize1.txt","r") as f:
    resize1 = f.read().splitlines()

f.close
with open("resize2.txt","r") as f:
    resize2 = f.read().splitlines()

f.close
with open("resize3.txt","r") as f:
    resize3 = f.read().splitlines()

f.close
resize1 = np.array((resize1),np.uint8)
resize1 = resize1.reshape(160,160)
resize2 = np.array((resize2),np.uint8)
resize2 = resize2.reshape(160,160)
resize3 = np.array((resize3),np.uint8)
resize3 = resize3.reshape(160,160)

resize = [resize3,resize1,resize2]
raw_image = open('lighthouse.raw','rb').read()
raw_image = np.frombuffer(raw_image, np.uint8)
img = raw_image[0:512*512]
img = np.reshape(img, (512,512))
img.setflags(write=1)

mask = np.array(([255]*160*160),np.uint8).reshape(160,160)


for i in range(512):
    for j in range(512):
        if np.array_equal(img[i:i+160,j:j+160],mask):
            print(i,j)
            print(i,j+160)
            print(i+160,j)
            print(i+160,j+160)
            print('next')
            img[i:i+160,j:j+160] = resize.pop()

plt.matshow(img,cmap='gray')
#plt.show()


   