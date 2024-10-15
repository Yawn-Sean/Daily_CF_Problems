import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import isqrt

def factorize(n):
    res = []
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            res.append(i)
            while n and n % i == 0:
                n //= i
            if n == 0:
                break
    if n > 1:
        res.append(n)
    return res

def solve():
    # key:如何討論圖形相等? A:圖的'邊'相同!
    # 選轉邊都會+1，再搭配取模檢查
    # 我們找到不重複的最大因子計算即可(最大因子的因子也會成立)
    # (找出n所有的質因子，再計算n//d) 
    # !注意: 計算輪迴取模，要從0開始計算
    
    ls, rs = [-1] * m, [-1] * m
    segs = set()
    for i in range(m):
        l, r = MII()
        l -= 1
        r -= 1
        if l > r: 
            l, r = r, l
        ls[i], rs[i] = l, r
        segs.add((l, r))    
    
    divs = [n // d for d in factorize(n)]
    for d in divs:
        for l, r in zip(ls, rs):
            l, r = (l + d) % n, (r + d) % n
            if l > r:
                l, r = r, l
            if (l, r) not in segs:
                break
        else:
            print('Yes')
            return
    print('No')
                           
for _ in range(1):
    n, m = MII()
    solve()