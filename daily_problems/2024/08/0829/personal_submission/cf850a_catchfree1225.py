import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from itertools import combinations

def solve():
    # key: 銳角->討論超平面(二維為最簡單情況)
    # 如何把點轉成座標向量? A:取其中一個為原點計算
    # 二維平均分割，四個向量夾角90度(最小角度)
    # 再多一個點，無論以誰為原點，都至少有一對會小於90度
    # 同理，五維33個向量(i.e.34個點一定有一對銳角)
    
    if n >= 34:
        print(0)
        return
    
    def dot(a, b):
        return sum(ai * bi for ai, bi in zip(a, b))
    
    def check(x, y, z): # 銳角
        u = tuple(yi - xi for xi, yi in zip(a[x], a[y]))
        v = tuple(zi - xi for xi, zi in zip(a[x], a[z]))
        return dot(u, v) > 0
    
    ans = set(range(n))
    for x, y, z in combinations(range(n), 3):
        if check(x, y, z):
            ans.discard(x)
        if check(y, x, z):
            ans.discard(y)
        if check(z, x, y):
            ans.discard(z)
    
    print(len(ans))
    print(*[x + 1 for x in ans], sep='\n')
    

for _ in range(1):
    n = int(input())
    a = [tuple(MII()) for _ in range(n)]
    solve()