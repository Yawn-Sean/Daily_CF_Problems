def main():
    x, y, k = MII()
    if max(x, y) > k:
        return -1
    a, b = 0, 0
    if x & 1 != k & 1:
        a = 1
    if y & 1 != k & 1:
        b = 1
    if a == 1 and b == 1:
        if k == 1:
            return -1
        return k - 2
    if max(a, b) == 1:
        return k - 1
    return k


T = II()
for ii in range(T):
    print(main())
