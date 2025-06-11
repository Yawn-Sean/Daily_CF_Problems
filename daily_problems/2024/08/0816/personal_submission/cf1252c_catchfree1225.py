import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())

def solve():    
    # key: BFS會超時，怎麼判斷移動路徑?
    # 染色法: 連通區域附上同顏色，移動方法只有上下與左右兩種
    # a[i][j] = r[i] + c[j]
    # 固定i, j: 只需考慮奇偶性是否相同
    # 因為兩路徑獨立，可以把判斷O(n^2)降為O(n)
    
    pr = list(range(n))
    for i in range(n - 1):
        if (r[i + 1] - r[i]) % 2 == 0:
            pr[i + 1] = pr[i]
    
    pc = list(range(n))
    for j in range(n - 1):
        if (c[j + 1] - c[j]) % 2 == 0:
            pc[j + 1] = pc[j]
    
    outs = ['NO'] * m
    for qi in range(m):
        r1, c1, r2, c2 = GMI()
        if pr[r1] == pr[r2] and pc[c1] == pc[c2]:
            outs[qi] = 'YES'
    print(*outs, sep='\n')
    
    
for _ in range(1):
    n, m = MII()
    r = list(MII())
    c = list(MII())
    solve()