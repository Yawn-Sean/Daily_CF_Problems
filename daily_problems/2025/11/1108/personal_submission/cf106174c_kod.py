n = II()
k = II()

def fun(n):
    s = d = 1
    res = 0
    for i in range(18):
        if s > n:
            break
        res += min(s * 9, n - s + 1) * d
        s *= 10
        d += 1
    return res

l, r = 0, 10 ** 18
while l <= r:
    m = (l + r) >> 1
    if fun(m + n - 1) - fun(m - 1) < k:
        l = m + 1
    else:
        r = m - 1
print(l if fun(l + n - 1) - fun(l - 1) == k else "-1")
