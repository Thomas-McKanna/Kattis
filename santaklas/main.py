from math import cos, floor, pi

H, v = [int(i) for i in input().split()]
if 0 <= v <= 180:
    print('safe')
elif 181 <= v <= 269:
    angle = 90 - (v - 180)
    print(floor(H / cos(angle * pi / 180)))
elif v == 270:
    print(H)
elif 271 <= v <= 359:
    angle = v - 270
    print(floor(H / cos(angle * pi / 180)))
