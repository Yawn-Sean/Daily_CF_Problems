from functools import cmp_to_key
from collections import  *
import sys
def cmp(i,j):
    if s[i] * h[j] > s[j] * h[i]: return -1  #不交换
    if s[i] * h[j] < s[j] * h[i]: return 1   #交换
    return 0
input = lambda :sys.stdin.readline().rstrip()
n = int(input())
li = []
for _ in range(n):
    li.append(input())
s = [li[i].count('s') for i in range(n)]
h = [li[i].count('h') for i in range(n)]

opt = sorted(range(n),key = cmp_to_key(cmp))
ans = 0
opt_s = ''.join(li[opt[i]] for i in range(n))
cnt = Counter(opt_s)
cnt_s = 0
#统计最终字符串sh的个数
for x in opt_s:
    if x == 's':
        ans += cnt['h']
    else:
        cnt['h'] -= 1
print(ans)
