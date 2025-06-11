import sys
from random import shuffle
from collections import Counter
input = lambda: sys.stdin.readline().strip()
'''
   求(a[i] * pow(10, Lj) + a[j]) % k == 0 且 i < j的个数
   枚举j找前面的i
'''
n, k = map(int, input().split())
nums = list(map(int, input().split()))
shuffle(nums)
cnt = [Counter([x * pow(10, i) % k for x in nums]) for i in range(11)]
res = 0
for x in nums:
    L = len(str(x))
    res += cnt[L][(-x) % k]
    if (x * pow(10, L) + x) % k == 0:
        res -= 1
print(res)
