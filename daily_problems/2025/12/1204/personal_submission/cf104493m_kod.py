t = ix()
for i in range(t):
    r, n, l = il()
    res = r * r * pi
    res += r * l * n
    res += l * l * n / 4 / tan(pi / n)
    print(res)
