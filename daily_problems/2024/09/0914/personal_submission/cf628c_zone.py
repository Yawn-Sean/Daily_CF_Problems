# submission url: https://codeforces.com/contest/682/submission/281062902

n = int(input())
a = list(map(int, input().split())) 

edge = [0]
tree = [[] for _ in range(n)]
for u in range(1, n):
    p, c = map(int, input().split())
    edge.append(c)
    tree[p - 1].append(u)

stk = [0] 
dp = [0] * n 
ans = 0 

while stk: 
    u = stk.pop()
    ans += 1 
    for v in tree[u]: 
        dp[v] = max(0, dp[u]) + edge[v]
        if dp[v] <= a[v]: 
            stk.append(v)

print(n - ans)
