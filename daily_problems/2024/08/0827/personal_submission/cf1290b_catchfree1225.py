import sys
input = lambda: sys.stdin.readline().strip()
GMI = lambda: map(lambda x: int(x) - 1, input().split())

class BIT:
    def __init__(self, n):
        self.tr = [0] * (n + 1)
        
    def add(self, i, val):
        i += 1
        while i < len(self.tr):
            self.tr[i] += val
            i += i & -i
    
    def preSum(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.tr[i]
            i &= i - 1
        return res        

def solve():
    # key: irreducible每堆'元素種類'必須不同!
    # 怎麼構成不同堆? A:分類元素(移動段中不同元素)，破壞對稱性
    # 用BIT快速預處理每段元素種類
    # case1: 長度為1 or >=3種類(一定irreducible)
    # case2: 2種元素，討論開頭與結尾元素種類
    # (如果開頭跟結尾相同，左右對稱不能分離)
    
    qs = [[] for _ in range(len(s))]
    for qi in range(q):
        l, r = GMI()
        qs[r].append((l, qi))
    
    cnt = [0] * q
    vis = [-1] * 26
    tr = BIT(len(s))
    for r, x in enumerate(s):
        if vis[x] != -1:
            tr.add(vis[x], -1)
        vis[x] = r
        tr.add(r, 1)
        for l, qi in qs[r]:
            cnt[qi] = tr.preSum(r) - tr.preSum(l - 1)
    
    outs = [None] * q
    for r, qr in enumerate(qs):
        for l, qi in qr:
            if l == r or cnt[qi] >= 3:
                outs[qi] = 'Yes'
            elif s[l] == s[r]:
                outs[qi] = 'No'
            else:
                outs[qi] = 'Yes'     
    print(*outs, sep='\n')
    
               
for _ in range(1):
    s = [ord(x) - 97 for x in input()]
    q = int(input())
    solve()