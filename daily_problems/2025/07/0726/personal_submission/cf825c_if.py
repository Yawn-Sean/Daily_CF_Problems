if 1:
    import sys  
    #sys.stdout.flush()   print('.....', flush = True)
    #import random #random.shuffle()
    from itertools import *
    from heapq import *
    from bisect import bisect_left, bisect_right
    from collections import Counter, deque, defaultdict
    input = lambda: sys.stdin.readline().strip()
    import math
    inf = math.inf
    #rdm = random.getrandbits(30)
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


n, k = MII()
a = LII()
a.sort()
ans = 0
i = 0
while i < n:
    if k * 2 >= a[i]:
        k = max(k, a[i])

        i += 1
        continue
    k *= 2
    ans += 1
print(ans)
