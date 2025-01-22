n, k = RII()
a = RILIST()
l = ans = 0
while l < n:
    s = 1
    r = l
    while r < n:
        s *= a[r]
        s %= k
        if s == 0:
            break
        r += 1
    # 向前找最小满足区间[l0, r]
    l0 = r
    if r < n:
        s = 1
        while l0 >= l:
            s *= a[l0]
            s %= k
            if s == 0:
                break
            l0 -= 1
        ans += (l0 - l + 1) * (n - r)
    l = l0 + 1
print(ans)
