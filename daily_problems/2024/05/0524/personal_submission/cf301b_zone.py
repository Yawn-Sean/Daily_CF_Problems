"""
url: 
    question:   https://codeforces.com/problemset/problem/301/B
    submission: https://codeforces.com/contest/301/submission/262370009
time: 281 ms
"""
def solve():
    n, m = map(int, input().split())
    cost = list(map(int, input().split()))
    a = [[]] + [list(map(int, input().split())) for _ in range(n)]
    adj = [[0] * (n + 1) for _ in range(n + 1)]
    dist = [10 ** 10] * (n + 1)
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            adj[i][j] = (m * (abs(a[i][0] - a[j][0]) + abs(a[j][1] - a[i][1])) 
                         - (cost[i - 2] if 2 <= i <= n - 1 else 0))
            adj[j][i] = (m * (abs(a[i][0] - a[j][0]) + abs(a[j][1] - a[i][1])) 
                         - (cost[j - 2] if 2 <= j <= n - 1 else 0))
    dist[1] = 0
    st = [0] * (n + 1)
    for i in range(1, n + 1):
        t = -1
        for j in range(1, n + 1):
            if not st[j] and (t == -1 or dist[j] < dist[t]): t = j 
        st[t] = 1 
        for j in range(1, n + 1):
            dist[j] = min(dist[j], dist[t] + adj[t][j])
    print(dist[n])
solve()
