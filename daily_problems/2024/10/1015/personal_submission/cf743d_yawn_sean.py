# Submission link: https://codeforces.com/contest/743/submission/285970165
def main():
    n = II()
    nums = LII()

    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    parent = [-1] * n
    order = []

    stk = [0]
    while stk:
        u = stk.pop()
        order.append(u)
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                stk.append(v)

    inf = 10 ** 15

    dp = [0] * n
    dp1 = [-inf] * n
    dp2 = [-inf] * n

    ans = -inf

    for i in reversed(order):
        dp[i] += nums[i]
        
        if i > 0:
            p = parent[i]
            dp[p] += dp[i]
            
            v = fmax(dp[i], dp1[i])
            if v >= dp1[p]:
                dp1[p], dp2[p] = v, dp1[p]
            elif v > dp2[p]:
                dp2[p] = v
        
        if dp2[i] > -inf:
            ans = fmax(ans, dp1[i] + dp2[i])

    print(ans if ans > -inf else 'Impossible')