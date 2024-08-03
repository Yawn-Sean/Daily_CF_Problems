def main():
    n, k = MII()
    s = I()
    ls = LGMI()
    rs = LGMI()
    group = [-1] * n
    for i in range(k):
        for j in range(ls[i], rs[i] + 1):
            group[j] = i
    q = II()
    pos = LGMI()
    diff = [0] * (n + 1)

    for x in pos:
        y = ls[group[x]] + rs[group[x]] - x
        if x > y:
            x, y = y, x
        diff[x] ^= 1
        diff[y + 1] ^= 1
    for i in range(1, n + 1):
        diff[i] ^= diff[i - 1]
    print(
        "".join(
            s[i] if diff[i] == 0 else s[ls[group[i]] + rs[group[i]] - i]
            for i in range(n)
        )
    )
    return
