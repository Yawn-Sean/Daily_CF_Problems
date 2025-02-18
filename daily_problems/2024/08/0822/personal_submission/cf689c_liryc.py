'''
https://codeforces.com/contest/689/submission/277596124
689C
2024/8/22 Y1
1700
Binary Search
'''

from bisect import bisect_left

def check(n):
    k = 2
    k3 = k ** 3
    c = 0
    while k3 <= n:
        c += n // k3
        k += 1
        k3 = k ** 3
    return c

m = int(input())
# 试算出来得到最大答案比9e15大一点，所以上界用1e16
n = bisect_left(range(10 ** 16), m, key=check)
if check(n) == m:
    print(n)
else:
    print(-1)


