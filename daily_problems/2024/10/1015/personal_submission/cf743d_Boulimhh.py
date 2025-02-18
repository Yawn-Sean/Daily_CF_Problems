"""
思路：整体的思路是求一个树上,不相交的两个子树权重之和的最大值。

依次求最大子树权重和与次大子树权重和， 二者相加来更新答案。

"""
#python 代码：
n = int(input())
a = list(map(int, input().split()))
path = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
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
fi_ma = [-inf] * n
se_ma = [-inf] * n
ans = -inf

for i in reversed(order):
    dp[i] += a[i]
    if i >= 0:
        p = parent[i]
        dp[p] += dp[i]  
        v = max(dp[i], fi_ma[i])
        if v >= fi_ma[p]: fi_ma[p], se_ma[p] = v, se_ma[p]
        elif v > se_ma[p]: se_ma[p] = v
    if se_ma[i] > -inf: ans = max(ans, fi_ma[i] + se_ma[i])
print(ans if ans > -inf else 'Impossible')
