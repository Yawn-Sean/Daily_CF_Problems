import sys
input = lambda: sys.stdin.readline().rstrip()


def soviet():
    n, m = map(int, input().split())
    a = [0] + sorted(list(map(int, input().split())))
    s = [0] * (n + 1)
    for i in range(1, n + 1):
        s[i] = s[i - 1] + a[i]

    ans = 0

    def check(mid) -> bool:
        nonlocal ans
        ans = 0
        cnt = 0
        l, r = 1, 1
        while l <= n:
            while r <= n and a[r] - a[l] < mid:
                r += 1
            if r <= n:
                cnt += (n - r + 1) << 1
                ans += (s[n] - s[r - 1] - (n - r + 1) * a[l]) << 1
            l += 1
        ans -= mid * (cnt - m)
        return cnt >= m
    
    l, r = 0, a[n] - a[1]
    while (l < r):
        mid = l + r + 1 >> 1
        if check(mid):
            l = mid
        else:
            r = mid - 1

    check(l)
    print(ans)


MT = int(input())
for _ in range(MT):
    soviet()
