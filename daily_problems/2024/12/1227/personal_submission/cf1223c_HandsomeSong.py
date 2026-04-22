from math import gcd
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
q = II()
for _ in range(q):
    n = II()
    p = LII()
    x, a = MII()
    y, b = MII()
    k = II() * 100
    p.sort(reverse=True)
    s = [0] * (n + 1)
    for i in range(1, n + 1):
        s[i] = s[i-1] + p[i-1]
    L = (a * b) // gcd(a, b)
    def check(m):
        c_both = m // L
        c_a = m // a - c_both
        c_b = m // b - c_both
        
        idx1 = c_both
        if x > y:
            idx2 = idx1 + c_a
            idx3 = idx2 + c_b
        else:
            idx2 = idx1 + c_b
            idx3 = idx2 + c_a
        kk = (x + y) * (s[idx1]) \
             + max(x, y) * (s[idx2] - s[idx1]) \
             + min(x, y) * (s[idx3] - s[idx2])        
        return kk >= k
    l, r = 1, n
    ans = -1
    while l <= r:
        m = (l + r) // 2
        if check(m):
            ans = m
            r = m - 1
        else:
            l = m + 1
    print(ans)
