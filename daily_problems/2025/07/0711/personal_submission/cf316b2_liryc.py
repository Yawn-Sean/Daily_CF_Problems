'''
https://codeforces.com/problemset/submission/316/328480164
'''
# dsu + knapsack
def solve(n: int, x: int, a: list[int]) -> list[int]:
    x -= 1
    x_cnt, x_parent = 0, -1
    for i in range(n):
        a[i] -= 1
    vis = [-1] * n
    cnt = [0] * n
    y = x
    stk = []
    while vis[y] < 0:
        if a[y] < 0:
            x_parent = vis[y] = y
            for i in stk:
                vis[i] = y
            x_cnt = cnt[y] = len(stk) + 1
        else:
            stk.append(y)
            y = a[y]
    for i in range(n):
        if vis[i] < 0:
            y = i
            stk = []
            while True:
                if vis[y] >= 0:
                    for j in stk:
                        vis[j] = vis[y]
                    cnt[vis[y]] += len(stk)
                    break
                if a[y] < 0:
                    vis[y] = y
                    for j in stk:
                        vis[j] = y
                    cnt[y] = len(stk) + 1
                    break
                else:
                    stk.append(y)
                    y = a[y]
    b = []
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(n):
        if a[i] < 0 and i != x_parent:
            b.append(cnt[i])
    for k in b:
        for j in range(n, k - 1, -1):
            if dp[j - k]:
                dp[j] = 1
    return [i + x_cnt for i in range(n) if dp[i]]
