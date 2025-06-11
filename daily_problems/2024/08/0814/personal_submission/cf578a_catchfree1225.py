import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: x可能為float, pieces為整數    
    # 圖只有三種case: 不存在，線段左右側
    if a < b: # 鋸齒圖在y=x下方
        print(-1)
        return
    
    ans = 1e15
    
    # case1: 在線段左側
    preDist = a - b
    if preDist / 2 >= b:
        pieces = preDist // (b * 2)
        ans = min(ans, preDist / pieces / 2)
    
    # case2: 在線段右側    
    preDist = a + b
    if preDist / 2 >= b:
        pieces = preDist // (b * 2)
        ans = min(ans, preDist / pieces / 2) 
    
    print(ans)
    
                   
for _ in range(1):
    a, b = MII()
    solve()