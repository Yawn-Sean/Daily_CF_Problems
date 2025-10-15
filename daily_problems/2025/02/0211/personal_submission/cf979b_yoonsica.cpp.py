import sys
from collections import defaultdict

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/979/B

三个长度相同的字符串，包含大小写字母。m轮游戏，每轮每个字符串都要改变一个字符为不同字符。
最后比较出现最多次数的子串出现次数。

字符串长度1e5
思路：
考虑极端情况，所有字符如果都相同，最理想情况，次数为字符串长度。至少需要n - max(cnt)次操作，只要m够大，答案就为字符串长度。
如果abc出现多次，那么a肯定也出现多次，所以不用考虑长度大于1的子串，就考虑单个字符出现次数即可。

wa:
1
aaaaaaaaaa
AAAAAAcAAA
bbbbbbzzbb

注意初始全一样的情况，如果m是1那么答案为n - 1,否则先变成其他的，最后变回来就行答案n

wa:
0
aaa
aab
ccd
m还能为0
'''
m = RI() #游戏轮数


def solve(s):
    n = len(s)
    mx_v = 0
    cnt = defaultdict(int)
    for i, x in enumerate(s):
        cnt[x] += 1
        mx_v = mx(mx_v, cnt[x])
    if m == 0:
        return mx_v
    if mx_v == n:
        return n if m > 1 else n - 1
    if n - mx_v <= m:
        return n
    else:
        return mx_v + m


ans = [0] * 3
for i in range(3):
    ans[i] = solve(RS())

# "Kuro", "Shiro" or "Katie"
m = {0:'Kuro', 1:'Shiro', 2:'Katie'}
b = sorted(range(3), key=lambda i: ans[i])
if ans[b[-1]] == ans[b[-2]]:
    print('Draw')
else:
    print(m[b[-1]])