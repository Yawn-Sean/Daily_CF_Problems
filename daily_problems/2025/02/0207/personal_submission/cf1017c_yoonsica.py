import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1017/C
史密斯夫人正试图联系她的丈夫约翰-史密斯，但她忘记了秘密电话号码！

史密斯太太唯一记得的是， $n$ 的任何排列都可能是秘密电话号码。只有那些秘密值最小的排列才可能是她丈夫的电话。

如果 $n$ 整数序列包含了从 $1$ 到 $n$ 的所有整数，那么这个序列就叫做排列。

电话号码的秘密值定义为最长递增子序列长度（LIS）和最长递减子序列长度（LDS）之和。

因此，请帮助史密斯太太找到一种排列，使 LIS 和 LDS 的长度之和最小。

思路：
考虑极端情况，全递增，则答案n
有一处递减，则LDS至少=2
那么我们考虑让LDS长，LIS短，一段递增+另一段递增，前一段整体大于后一段，那么LDS=段数量，LIS=最长的一段
段越多LDS越长，越少LIS越长，考虑枚举分x段,每一段L= (n + x - 1)// x,ans = x + L
'''
n = RI()
ans = []
mx_v = inf
cnt = 0
for x in range(1, n + 1):
    if x + (n + x - 1) // x < mx_v:
       cnt, mx_v = x,  x + (n + x - 1) // x
if cnt <= 1:
    ans = list(range(1, n + 1))
else:
    for i in range(n, 0, -cnt):
        ans += [x for x in range(mx(1, i - cnt + 1), i + 1)]
print(' '.join(map(str, ans)))