a, b, c, d, e, f = MII()

if 0 not in [a, b, c, d, e, f]:
    if b * d * f > a * c * e:
        print("Ron")
    else:
        print("Hermione")
else:
    if c == 0 and d > 0:
        print("Ron")
    elif a == 0 and b > 0 and d > 0:
        print("Ron")
    elif e == 0 and f > 0 and b > 0 and d > 0:
        print("Ron")
    else:
        print("Hermione")
