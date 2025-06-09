import sys
from collections import defaultdict
from itertools import pairwise
from math import comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
mod = 10**9 + 7

'''
https://www.luogu.com.cn/problem/CF439C

你有n个数，a1，a2，……，an 给出k和p，要求将这些数分成k堆，其中p堆的每堆中所有数之和为偶数，其余k-p堆的每堆中所有数之和为奇数

输入：n，k，p（1≤k≤n≤10^5，0≤p≤k），a1，a2，……，an（int范围内） 输出：一种方案，无解输出"NO"

奇数堆必须有奇数，偶数堆可以没有偶数
'''
n, k, p = RII()
even, odd = [], []
cnt_e = cnt_o = 0
for x in RILIST():
    if x & 1:
        odd.append(x)
        cnt_o += 1
    else:
        even.append(x)
        cnt_e += 1

if cnt_o < k - p or (cnt_o - (k - p)) // 2 + cnt_e < p:
    exit(print('NO'))

# 先处理奇数
if (cnt_o - (k - p)) & 1:
    exit(print('NO'))

ans = []
# 先凑够k - p个奇数堆
i = cnt = 0
while i < k - p and cnt < k - 1:
    ans.append((1, odd[i]))
    i += 1
    cnt += 1

# 剩下的奇数两个一组凑偶数堆，第k堆留着放多余的数
while i < cnt_o and cnt < k - 1:
    ans.append((2, odd[i], odd[i + 1]))
    i += 2
    cnt += 1

# 偶数一个一堆
j = 0
while cnt < k - 1 and j < cnt_e:
    ans.append((1, even[j]))
    j += 1
    cnt += 1

# 第k堆放剩下的所有数
x = cnt_o - i + cnt_e - j
if x <= 0:
    exit(print('NO'))
print('YES')
a = [x] + odd[i:] + even[j:]
print(' '.join(map(str, a)))
for x in ans:
    print(*x)
