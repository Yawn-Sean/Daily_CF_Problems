a, b = MII()
if a < b:
    print(-1)
elif a == b:
    print(a)
else:
    if ((a - b) // b) % 2 != 0:
        tmp1 = ((a - b) // b) - 1
    else:
        tmp1 = ((a - b) // b)
    if ((a + b) // b) % 2 != 0:
        tmp2 = ((a + b) // b) - 1
    else:
        tmp2 = ((a + b) // b)
    if tmp1 == 0:
        print(min(max(a, b), (a + b) / tmp2))
    else:
        print(min((a - b) / tmp1, (a + b) / tmp2))
