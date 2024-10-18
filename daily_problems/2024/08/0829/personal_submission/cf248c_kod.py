y1, y2, yw, xb, yb, r = il()
y1, y2 = 2 * yw - y2 - 2 * r,  2 * yw - y1 - 2 * r
if r * r * ((yb - y2 + r) ** 2 + xb ** 2) > (y2 - y1 - r) ** 2 * xb * xb:
    print( - 1)
else:
    print((y2 - yw) * xb / (y2 - r - yb))
