a, b, mod = MII()
if b >= mod:
    print(2)
else:
    for i in range(1, min(a, mod) + 1):
        i *= 10 ** 9
        tmp = i % mod
        if tmp != 0 and tmp + b < mod:
            print(1, f"{i // 10 ** 9:0{9}d}")
            exit()
    print(2)
