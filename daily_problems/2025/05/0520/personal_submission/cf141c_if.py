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
s = []
for i in range(n):
    p = LSI()
    p[1] = int(p[1])
    s.append(p[:])

s.sort(key = lambda x : x[1])
ans = []
for i in s:
    if i[1] > len(ans):
        print(-1)
        exit()
    ans.insert(len(ans) - i[1], i[0])
ids = 1
hash = dict()
for i in ans:
    hash[i] = ids
    ids += 1
ans = []
for i in s:
    ans.append(hash[i[0]])
for i in range(len(ans)):
    print(s[i][0], ans[i])

