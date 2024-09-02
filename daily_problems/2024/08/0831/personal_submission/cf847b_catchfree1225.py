import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 可以同步分組計算，無需真的分次
    # (用二分尋找插入位置，尾端會形成遞減序列)
    g = []
    for x in a:
        l, r = 0, len(g)
        while l < r:
            mid = (l + r) >> 1
            if g[mid][-1] < x:
                r = mid
            else:
                l = mid + 1
        
        if l == len(g):
            g.append([x])
        else:
            g[l].append(x)
        
    for gi in g:
        print(*gi)    
                   
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()