import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import gcd
from collections import Counter

def solve():
    # 直線計算小技巧，換成向量表示法
    # 用gcd化簡成有理數
    lines = set()
    for i in range(n):
        for j in range(i + 1, n):
            x1, y1 = a[i]
            x2, y2 = a[j]
            if x1 == x2:
                lines.add(((0, 1), x1))
            else:  
                dx, dy = x2 - x1, y2 - y1
                g = gcd(dx, dy)
                dx //= g
                dy //= g
                if dx < 0:
                    dx, dy = -dx, -dy
                v = dy * x1 - dx * y1
                lines.add(((dx, dy), v))
    
    sz = len(lines)
    ans = sz * (sz - 1) // 2 # C(sz, 2)
    slopes = Counter() # 直接暴力O(m^2)會超時
    for m, _ in lines:
        ans -= slopes[m]
        slopes[m] += 1
    print(ans)
    
               
for _ in range(1):
    n = int(input())
    a = [tuple(MII()) for _ in range(n)]
    solve()