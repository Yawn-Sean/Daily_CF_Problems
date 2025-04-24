if 1:
    import typing
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
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
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


for _ in range(II()):
    n, m, a, b = MII()
    fang = min(m, abs(b - a) - 1)
    nums = LII()
    nums.sort()

    da = b - 1 if a < b else n - b

    xiao = a - 1 if a < b else n - 1 - a
    st = [max(nums[0], xiao)]
    for i in nums[1::]:
        if i <= st[-1]:
            st.append(st[-1] + 1)
        else:
            st.append(i)
    print(min(fang, bisect_left(st, da)))

