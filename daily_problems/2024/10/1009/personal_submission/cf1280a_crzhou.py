MOD = 10 ** 9 + 7
t = II()
outs = []

for _ in range(t):
    x = II()
    s = I()
    n = len(s)

    
    tmp = [0] * x
    for i in range(fmin(n, x)):
        tmp[i] = int(s[i]) - 1
    l = 0
    while n < x and l < x:
        left = n
        right = min(x, n + (n - l - 1) * tmp[l])
        for i in range(left, right):
            tmp[i] = tmp[i - (n - l - 1)]
        # s += s[l + 1:] * cur
        n += (n - l - 1) * tmp[l] % MOD
        l += 1
    
    while l < x:
        n += (n - l - 1) * tmp[l] % MOD
        l += 1

    outs.append(n % MOD)

print("\n".join(map(str, outs)))
