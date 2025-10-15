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


def f(i):
    if i < 10:
        return i
    ans = 0
    for d in range(1, 100):
        if 10 ** d <= i:
            ans += 10 ** (d - 1) * 9 * d
        else:
            break
    
    ans += (i - 10 ** (d - 1) + 1) * d
    return ans

w, m, k = MII()
w //= k

l = 0
r = w
while l < r:
    mid = l + r + 1 >> 1
    if f(mid + m - 1) - f(m - 1) <= w:
        l = mid
    else:
        r = mid - 1 
print(l)
