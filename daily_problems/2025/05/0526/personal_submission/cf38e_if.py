if 1:
    import sys  
    #sys.stdout.flush()   print('.....', flush = True)
    import random #random.shuffle()
    from itertools import *
    from heapq import *
    from bisect import bisect_left, bisect_right
    from collections import Counter, deque, defaultdict
    input = lambda: sys.stdin.readline().strip()
    import math
    inf = math.inf
    rdm = random.getrandbits(30)
    #sys.set_int_max_str_digits(6000)
    def I():
        return input()
    def II():
        return int(input())
    def MII():
        return map(int, input().split())
    def LI():
        return list(input())
    def LII():
        return list(map(int, input().split()))
    def LFI():
        return list(map(float, input().split()))
    def LSI():
        return list(map(str, input().split()))
    mod = int(1e9 + 7) 
    mod = 998244353

n = II()
a = []
for _ in range(n):
    a.append(LII())
a.sort(key = lambda x: x[0])
a.append([inf, 0])
dp = [inf] * (n + 1)
dp[-1] = 0
for i in range(n - 1, -1, -1):
    cnt = 0
    for j in range(i + 1, n + 1):
        cnt += a[j - 1][0]
        dp[i] = min(dp[i], a[i][1] + dp[j] + cnt - (j - i) * a[i][0])
print(dp[0])
