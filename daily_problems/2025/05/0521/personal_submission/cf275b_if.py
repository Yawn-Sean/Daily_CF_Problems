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
ans = 'YES'
n, m = MII()
a = []
for _ in range(n):
    a.append(I())

p = []

for i in range(n):
    for j in range(m):
        if a[i][j] == 'B':
            p.append((i + 1, j + 1))

for i in range(len(p)):
    for j in range(i + 1, len(p)):
        x1, y1 = p[i]
        x2, y2 = p[j]
        if x1 == x2:
            for k in range(y1, y2 + (y1 * y2) // (abs(y1 * y2)), (y1 * y2) // (abs(y1 * y2))):
                if a[x1 - 1][k - 1] == 'W':
                    ans = 'NO'
        elif y1 == y2:
            for k in range(x1, x2 + (x1 * x2) // (abs(x1 * x2)), (x1 * x2) // (abs(x1 * x2))):
                if a[k - 1][y1 - 1] == 'W':
                    ans = 'NO'
        
        else:
            x3, y3 = x1, y2
            x4, y4 = x2, y1
            if a[x3 - 1][y3 - 1] == 'W' and a[x4 - 1][y4 - 1] == 'W':
                ans = 'NO'
print(ans)
