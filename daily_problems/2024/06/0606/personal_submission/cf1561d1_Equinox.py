import math
import random
import sys
from functools import reduce
from sortedcontainers import SortedList

sys.stdin = open('in.txt', 'r')
n, m = map(int, input().split())

f = [0] * (n + 1)
f[1] = 1
pre = 1
for i in range(2, n + 1):
    f[i] = pre
    l = 2
    while l <= i:
        r = i // (i // l) + 1
        f[i] = (f[i] + f[i // l] *  (r - l)) % m
        l = r
    pre = (pre + f[i]) % m

print(f[n])

'''
f[i]

f[i] = sum_{j = 1}^{j <= i - 1} f[j] + 
        sum_{k=2}^{k <= i} f[i / k]  -数论分块
'''
