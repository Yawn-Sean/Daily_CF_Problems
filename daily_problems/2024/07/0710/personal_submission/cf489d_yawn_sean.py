# Submission Link: https://codeforces.com/contest/489/submission/269643075
def main():
    n, m = MII()
    to = [0] * (n * n)

    def f(x, y):
        return x * n + y

    path = [[] for _ in range(n)]
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        to[f(u, v)] = 1

    cnt = [0] * n

    ans = 0
    for i in range(n):
        for j in path[i]:
            for k in path[j]:
                cnt[k] += 1
        for j in range(n):
            if j != i:
                ans += cnt[j] * (cnt[j] - 1) // 2
            cnt[j] = 0

    print(ans)