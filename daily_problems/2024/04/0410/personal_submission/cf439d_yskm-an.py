from sys import *
from collections import *
from math import *
input = stdin.readline
n, m = map(int, input().split())
arr = list(map(int, input().split()))
brr = list(map(int, input().split()))
c1 = Counter(arr)
c2 = Counter(brr)
crr = set()
mi = min(arr)
ma = max(brr)
if mi >= ma:
    print('0')
    exit(0)
for x in arr:
    if mi <= x <= ma:
        crr.add(x)
for x in brr:
    if mi <= x <= ma:
        crr.add(x)
crr = sorted(crr)
ans1 = []
num = [0, 0]
res1 = 0
for x in crr:
    if num[1] != 0:
        res1 += (x - num[1]) * num[0]
    ans1.append(res1)
    if x in c1:
        num[0] += c1[x]
    num[1] = x
ans2 = deque()
num = [0, 0]
res2 = 0
for x in crr[::-1]:
    if num[1] != 0:
        res2 += (num[1] - x) * num[0]
    ans2.appendleft(res2)
    if x in c2:
        num[0] += c2[x]
    num[1] = x
res = inf
for x, y in zip(ans1, ans2):
    res = min(res, x + y)
print(res)
