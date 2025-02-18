import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import gcd

def solve():
    def getLine(x1, y1, x2, y2):
        dx, dy = x2 - x1, y2 - y1
        if dx == 0:
            return 0, 1
        k = gcd(dx, dy)
        dx //= k
        dy //= k
        if dx < 0:
            dx, dy = -dx, -dy
        return dx, dy
    
    # key: 注意兩條線平行->找斜率，統計k
    # 怎麼找斜率? A:暴力->O(n^2)
    # 能更快嗎? A:討論v1,v2,v3關係
    # 再更快? A:鴿籠原理(O(1))!
    # 3個點產生3直線，要求總共兩個，必有兩個共線
    
    for i in range(3):
        for j in range(i):
            dx, dy = getLine(i, a[i], j, a[j]) # 兩條平行線斜率
            vis = set([dy * j - dx * a[j]]) # 截距k
            for xi, yi in enumerate(a):
                vis.add(dy * xi - dx * yi)
                if len(vis) > 2:
                    break
            if len(vis) == 2: # 總共只有兩條平行線
                print('Yes')
                return
    print('No')
                                
               
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()