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

n = II()
ans = inf
a = []
s = 0
mi = 0
for _ in range(n):
    w, h = MII()
    a.append([w, h])
    mi = max(mi, min(w, h))
    s = max(s, h, w)

end = inf
for cur in range(mi, s + 1):
    p = []
    ans = 0
    cnt = 0
    for w, h in a:
        if h > cur:
            cnt += 1
            ans += h
        else:
            if w > cur:
                ans += w
            else:
                p.append([w, h, w - h])
    p.sort(key = lambda x : x[-1])
    if cnt > n // 2:
        continue
    cnt = n // 2 - cnt
    while p and p[-1][-1] > 0 and cnt:
        ans += p.pop()[1]
        cnt -= 1
    while p:
        ans += p.pop()[0]
    
    
    end = min(end, ans * cur)
print(end)



    
