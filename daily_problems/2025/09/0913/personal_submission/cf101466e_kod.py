a = ip()
b = ip()
n = ix()
l, r = 1, len(b)
while l <= r:
    m = (l + r) // 2
    if kmp(a, b[:m]) >= n:
        l = m + 1
    else:
        r = m - 1
print(b[:r] if r else 'IMPOSSIBLE')
