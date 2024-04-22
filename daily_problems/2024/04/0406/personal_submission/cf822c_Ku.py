import  math
from collections import *
n,x = map(int,input().split())
left,right = [Counter() for _ in range(2 * 10 ** 5 + 1)],[Counter() for _ in range(2 * 10 ** 5 + 1)]
for i in range(n):
    l,r,c = map(int,input().split())
    dist = r - l + 1
    if dist not in left[l] or left[l][dist] > c:
        left[l][dist] = c
    if dist not in right[r] or right[r][dist] > c:
        right[r][dist] = c
cur = Counter()
ans = math.inf
for i in range(1,2 * 10 ** 5):
    for j in right[i]:
        if j not in cur or cur[j] > right[i][j]:
            cur[j] = right[i][j]                       #存的是第一个区间长度为j的最小费用
    for j in left[i+1]:                                #从i+1开始枚举左端点是为了保证两个区间不相交
        if x - j in cur:
            ans = min(ans,cur[x-j] + left[i+1][j])
print(ans if ans < math.inf else -1)
