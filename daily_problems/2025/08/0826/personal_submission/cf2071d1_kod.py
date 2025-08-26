t = ix()
for _ in range(t):
    n, l, r = il()
    a = il()
    v = 0
    if n % 2 == 0:
        for i in range(n // 2):
            v ^= a[i]
        a += v,
        n += 1
    res = reduce(xor, a)
    if l <= n:
        print(a[l - 1])
        continue

    def fun(x):
        if x <= n * 2:
            ans = 0
            for i in range(x // 2):
                ans ^= a[i]
            return ans

        t = x // 2
        if t % 2 == 0:
            return fun(t) ^ res
        else:
            return res

    print(fun(l))
