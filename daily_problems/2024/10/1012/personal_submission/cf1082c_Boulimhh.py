"""
思路： 学习的一集，可以用一个数组来统计相同人数下的技能总数， 妙啊！

之后遍历每个组， 对组排序，加和更新即可
"""
#python代码：
n, m = map(int, input().split())
g = [[] for _ in range(m + 1)]

for _ in range(n):
    s, r = map(int, input().split())
    g[s].append(r)
ans = [0] * (n + 1)
for i in range(m + 1):
    g[i].sort(reverse = True)
    cur = 0
    for j in range(len(g[i])):
        cur += g[i][j]
        if cur > 0: ans[j] += cur
print(max(ans)) 
