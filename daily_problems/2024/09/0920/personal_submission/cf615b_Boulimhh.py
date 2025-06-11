"""
思路： 先用图存储临边， 这样可以得到每个点作为中心时， 刺的数量。

观察可得尾部是点的序号数递减， 所以只需统计递减的长度， 并取每个点的max长度。

遍历长度和刺， 得到max的答案。

"""
#python代码：
n, m = map(int, input().split())
path = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    path[u].append(v)
    path[v].append(u)

cnt = [1] * n
for i in range(n):
    for j in path[i]:
        if j > i:
            cnt[j] = max(cnt[j], cnt[i]+1)
ans = 0
for i in range(n):
    ans = max(ans, cnt[i] * len(path[i]))
print(ans)
