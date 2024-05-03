# Submission link: https://codeforces.com/contest/1146/submission/259288237
def main():
    m, a, b = MII()

    max_vis = [inf] * (a + b + 1)
    max_vis[0] = 0

    def f(d, x):
        return d * (a + b + 1) + x

    hpq = [0]

    while hpq:
        d, x = divmod(heappop(hpq), a + b + 1)
        if max_vis[x] == d:
            if x <= b and max_vis[x+a] > max(max_vis[x], x + a):
                max_vis[x+a] = max(max_vis[x], x + a)
                heappush(hpq, f(max_vis[x+a], x + a))
            if x >= b and max_vis[x-b] > max_vis[x]:
                max_vis[x-b] = max_vis[x]
                heappush(hpq, f(max_vis[x-b], x - b))

    ans = 0
    for i in range(a + b + 1):
        if max_vis[i] <= m:
            ans += m - max_vis[i] + 1

    if m > a + b:
        for i in range(b + 1, a + b + 1):
            if max_vis[i] <= m:
                start = i + a
                end = i + (m - i) // a * a
                cnt = (end - start) // a + 1
                ans += (m * 2 - start - end + 2) * cnt // 2

    print(ans)