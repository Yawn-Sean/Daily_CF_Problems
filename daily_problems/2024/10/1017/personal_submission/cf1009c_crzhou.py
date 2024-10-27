n, m = MII()
tot = 0

for _ in range(m):
    x, d = MII()
    tot += x * n
    if d > 0:
        tot += d * n * (n - 1) // 2
    else:
        tmp = n
        if n % 2:
            n //= 2
            tot += d * n * (n + 1)
        else:
            n //= 2
            tot += d * n * n
        n = tmp
print(tot / n)
