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
a = LII()
cnt = Counter(a)
ans = cnt[0]
ans = max(ans, 2)
a.sort()
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if a[j] == 0 and a[i] == 0:
            continue
        p = []
        cnt[a[i]] -= 1
        cnt[a[j]] -= 1
        p.append(a[i])
        p.append(a[j])
        cur = 2
        laa = a[i]
        la = a[j]

        while cnt[laa + la]:
            p.append(laa + la)
            cnt[la + laa] -= 1
            t = la
            la = laa + la
            laa = t
            cur += 1
        while p:
            cnt[p.pop()] += 1
        ans = max(ans, cur)

print(ans)
            
