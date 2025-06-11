def main():
    n, m = map(int, input().split())

    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        g[u - 1].append(v - 1)

    ans = 0
    for i in range(n):
        cnt = [-1] * n
        for j in g[i]:
            for k in g[j]:
                cnt[k] += 1 
                ans += cnt[k] if k != i and cnt[k] > 0 else 0
    print(ans)
