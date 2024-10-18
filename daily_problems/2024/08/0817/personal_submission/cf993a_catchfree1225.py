import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 注意，第二個正方形角度一定為45度!
    # 兩種case: 1.頂點落在邊界 2.嚴格包含/互斥
    # case1: 邊界用水平、垂直正方形判斷
    # !(注意判斷是否在內側，得看平正方形，因此要旋轉)
    # case2: 要用中心點判斷，互斥中心點不會落在對面
    
    pa, pb = [], []
    for i in range(0, 7, 2):
        pa.append((a[i], a[i + 1]))
        pb.append((b[i], b[i + 1]))
    
    def is_in(pa, pb):
        xl = min(x for x, _ in pa)
        xr = max(x for x, _ in pa)
        yl = min(y for _, y in pa)
        yr = max(y for _, y in pa)
        
        for x, y in pb:
            if xl <= x <= xr and yl <= y <= yr:
                return True
            
        cxb = (pb[0][0] + pb[-1][0]) / 2
        cyb = (pb[0][1] + pb[-1][1]) / 2
        if xl <= cxb <= xr and yl <= cyb <= yr:
            return True
        
        return False

    if is_in(pa, pb):
        print('YES')
        return
        
    # 逆時針轉45度(忽略常數倍)
    def rotate(p):
        return [(x - y, x + y) for x, y in p]
    
    pa, pb = rotate(pa), rotate(pb)
    if is_in(pb, pa): # 反過來
        print('YES')
    else:
        print('NO')
    
               
for _ in range(1):
    a = list(MII())
    b = list(MII())
    solve()