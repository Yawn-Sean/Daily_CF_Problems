'''
https://codeforces.com/contest/615/submission/281930535
615B
2024/9/20 Y1
1600
graph dp
'''

if __name__ == '__main__':
    n, m = map(int, input().split())
    path = [[] for _ in range(n)]
    degs = [0] * n

    for _ in range(m):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        if u > v:
            u, v = v, u
        path[u].append(v)
        degs[u] += 1
        degs[v] += 1

    dp = [1] * n
    for i in range(n):
        for j in path[i]:
            dp[j] = max(dp[j], dp[i] + 1)

    print(max(x * y for x, y in zip(dp, degs)))