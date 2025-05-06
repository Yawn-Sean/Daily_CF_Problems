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

s1 = LI()
s2 = LI()
s1.sort()
s2.sort()
s1 = deque(s1)
s2 = deque(s2)
n = len(s1)

need1 = n + 1 >> 1
need2 = n >> 1

while len(s1) != need1:
    s1.pop()
while len(s2) != need2:
    s2.popleft()

ans = ['0'] * n
l = 0
r = n - 1

for i in range(n):
    if i % 2 == 0:
        if not s2:
            ans[l] = s1.pop()
            continue
        if s1[0] >= s2[-1]:
            ans[r] = s1.pop()
            r -= 1
        else:
            ans[l] = s1.popleft()
            l += 1
    else:
        if not s1:
            ans[l] = s2.pop()
            continue
        if s2[-1] <= s1[0]:
            ans[r] = s2.popleft()
            r -= 1
        else:
            ans[l] = s2.pop()
            l += 1
print("".join(ans))


