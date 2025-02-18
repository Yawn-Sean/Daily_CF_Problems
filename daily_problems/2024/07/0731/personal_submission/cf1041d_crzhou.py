from bisect import bisect_left


n, h = map(int, input().split())
pairs = [list(map(int, input().split())) for _ in range(n)]
pairs.sort()

pre = [0] * n

for i in range(1, n):
    pre[i] = pre[i-1] + pairs[i][0] - pairs[i - 1][1]

ans = 0
for i in range(n):
    id = bisect_left(pre, h + pre[i], i, n) - 1
    ans = max(ans, pairs[id][1] - pairs[i][0] + h - (pre[id] - pre[i]))
print(ans)
