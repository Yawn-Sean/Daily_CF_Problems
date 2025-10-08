MX = 10 ** 7 + 1
is_prime = [True] * MX
is_prime[1] = False
is_prime[0] = False
for i in range(2, MX):
    if is_prime[i]:
        for j in range(i * i, MX, i):
            is_prime[j] = False
pl = [0] * MX
for i in range(MX):
    pl[i] = pl[i - 1] + is_prime[i]
t = ix()
for i in range(t):
    n = ix()
    if n < 4:
        print(n - 2)
    else:
        print(pl[n] - pl[n // 2])
