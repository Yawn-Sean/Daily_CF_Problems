'''
https://codeforces.com/problemset/submission/743/286067712
743D
2024/10/15 Y1
1800
DP
'''
# ref
def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n, a):
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
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
        dp[i] += a[i]
        
        if i > 0:
            p = parent[i]
            dp[p] += dp[i]
            
            v = max(dp[i], dp1[i])
            if v >= dp1[p]:
                dp1[p], dp2[p] = v, dp1[p]
            elif v > dp2[p]:
                dp2[p] = v
        
        if dp2[i] > -inf:
            ans = max(ans, dp1[i] + dp2[i])
    return str(ans) if ans > -inf else 'Impossible'

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
