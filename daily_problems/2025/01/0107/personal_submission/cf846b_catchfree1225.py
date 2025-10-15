import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

# WA: 1, time: 45min, dt:20250107
def solve_gd():
    ans = 0
    tot = sum(t)
    for i in range(n + 1):
        time = M - i * tot
        if time < 0:
            break
        cur = i * (k + 1)
        for j in range(k):
            if time <= 0:
                break
            m = min(time // t[j], n - i)
            cur += m
            time -= m * t[j]
        ans = max(ans, cur)
    print(ans)

def solve():
    m = n * (k + 1)
    tot = sum(t)
    f = [0] + [int(1e18)] * m # f[i]: 達到i分的最短時間
    for _ in range(n):  # 不打亂任務順序
        g = f.copy()
        for i in range(m, k, -1):
            g[i] = min(g[i], f[i - (k + 1)] + tot)
        for j in range(k):
            for i in range(m, 0, -1):
                f[i] = min(f[i], f[i - 1] + t[j])
        f = [min(fi, gi) for fi, gi in zip(f, g)]
    
    for j in range(m, -1, -1):
        if f[j] <= M:
            print(j)
            break
               
for _ in range(1):
    n, k, M = MII()
    t = sorted(MII())
    solve()