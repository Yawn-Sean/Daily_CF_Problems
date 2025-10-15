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

n, m = MII()
edge = []
for i in range(m):
    f, t = MII()
    edge.append([f, t, i])
edge.sort(key = lambda x: (x[0], -x[1]))
ok = [1]
p = []
ans = [0] * m
ids = 2
for i in edge:
    if i[1] == 0:
        if p:
            ans[i[-1]] = p.pop()
        else:
            print(-1)
            exit()
    else:
        for f in ok:
            if len(p) > m:
                break
            if f != ids - 1:
                p.append([f, ids])
            
        ans[i[-1]] = [ids - 1, ids]
        ok.append(ids)
        ids += 1
for f, t in ans:
    print(f, t)



