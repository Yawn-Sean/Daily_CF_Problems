from functools import lru_cache
def main():
    d, m = map(int, input().split())
    @lru_cache(None)
    def f(t):
        if t == 0: return 0
        k = t
        if 2 * t - 1 > d:
            k = (d - t + 1)
        res = k
        while t:
            t >>= 1
            res = (res + k * f(t)) % m
        return res
    p = 1
    ans = 0
    while p <= d:
        ans = (ans + f(p)) % m
        p <<= 1
    print(ans)
T = int(input())

for _ in range(T):
    main()