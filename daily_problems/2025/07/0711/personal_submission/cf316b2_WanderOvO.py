"""
i 前面是 a[i]，则连 a[i] -> i
考虑 pos，其排名至少是其所在的那条链的排名
其他可能的情况，就是其他链做背包，然后加一下
"""

n, pos = map(int, input().split())
a = [0] + list(map(int, input().split()))
e = [[] for i in range(n + 1)]
degree = [0] * (n + 1)

for i in range(1, n + 1):
    if a[i] != 0:
        e[a[i]].append(i)
        degree[i] += 1

chains = [0]
min_rank = -1

for i in range(1, n + 1):
    if degree[i] == 0:
        cnt = 1
        has_pos = False
        u = i
        if u == pos:
            has_pos = True
            min_rank = cnt
        while len(e[u]) > 0:
            u = e[u][0]
            cnt += 1
            if u == pos:
                has_pos = True
                min_rank = cnt
        if not has_pos:
            chains.append(cnt)

assert min_rank != -1

dp = [False] * (n + 1)
dp[0] = True
m = len(chains)
for i in range(1, m):
    for j in range(n, -1, -1):
        if j >= chains[i]:
            dp[j] = (dp[j] or dp[j - chains[i]])
res = []
for i in range(0, n + 1):
    if dp[i]:
        res.append(i + min_rank)
res.sort()
for rank in res:
    print(rank)
