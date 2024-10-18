import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

class BIT:
    def __init__(self, n):
        self.tr = [0] * (n + 1)
    
    def add(self, i, val):
        while i < len(self.tr):
            self.tr[i] += val
            i += i & -i
    
    def preSum(self, i):
        res = 0
        while i > 0:
            res += self.tr[i]
            i &= i - 1
        return res
        
def solve(a):   
    # 刷油漆，從數字小的開始刷，數字小不會在數字大上面
    # 此題考點: 1.q最後刷，一定存在 2.數字是否都<=q(題目滿足)
    # 遇到數字為0，隨便刷成周圍數字就可以了
    zero_idx, preV = -1, 1
    hasQ = False
    for i, x in enumerate(a):
        if x == 0:
            zero_idx = i
            a[i] = preV
        else:
            if x == q:
                hasQ = True
            preV = x
    if not hasQ:
        if zero_idx != -1:
            a[zero_idx] = q
        else:
            print('NO')
            return
            
    pos = [[] for _ in range(q + 1)]
    for i, x in enumerate(a, 1): # 樹狀數組下從1開始
        pos[x].append(i)
    
    tr = BIT(n)
    for x, px in enumerate(pos):
        if not px:
            continue
        l, r = px[0], px[-1]
        if tr.preSum(r) - tr.preSum(l - 1): # 要覆蓋小於x的數字，不合法
            print('NO')
            return
        for p in px:
            tr.add(p, 1)
    print('YES')
    print(*a)
    
               
for _ in range(1):
    n, q = MII()
    a = list(MII())
    solve(a)