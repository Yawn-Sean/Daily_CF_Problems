import sys

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
d, p, c, ex, ly, ry = [0] * n, [0] * n, [0] * n, [0.0] * n, [0] * n, [0] * n
for _ in range(n):
    d[_], p[_], c[_], lx, rx, ly[_], ry[_] = map(int, input().split())
    ex[_] = (lx + rx) / 2

S = 1 << n
dp = [0.0] * S
for s in range(S):
    idx = [i for i in range(n) if s >> i & 1]
    t = sum(c[i] for i in idx)
    res = 0
    for i in idx:
        nw = dp[s ^ (1 << i)]
        if t <= d[i]:
            nw += p[i]
            if t <= ly[i]:
                nw += ex[i]
            elif t <= ry[i]:
                nw += ex[i] * (ry[i] - t) / (ry[i] - ly[i])
        res = max(res, nw)
    dp[s] = res
print(f"{max(dp):.12f}")
