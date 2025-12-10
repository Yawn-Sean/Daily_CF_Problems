t = ix()
for i in range(t):
    r, l, th = il()
    th = th / 180 * pi
    a = 2 * r * sin(th / 2)
    b = sqrt(l * l - a * a)
    print(b)
