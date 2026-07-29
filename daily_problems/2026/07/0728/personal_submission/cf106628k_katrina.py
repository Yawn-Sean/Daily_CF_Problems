import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    xs = []
    ys = []
    for _ in range(n):
        x, y = map(int, input().split())
        xs.append(x - y)
        ys.append(x + y)
    
    if n <= 3:
        print(0)
        return
    
    st1 = sorted(range(n), key=lambda i: xs[i])
    st2 = sorted(range(n), key=lambda i: ys[i])
    
    idxs = st1[:2] + st1[-2:] + st2[:2] + st2[-2:]
    
    inf = 4 * 10 ** 9
    ans = inf
    
    for i in range(8):
        for j in range(i):
            i1 = idxs[i]
            i2 = idxs[j]
            
            mi_x = inf
            ma_x = -inf
            mi_y = inf
            ma_y = -inf
            
            for idx in range(n):
                if idx != i1 and idx != i2:
                    mi_x = min(mi_x, xs[idx])
                    ma_x = max(ma_x, xs[idx])
                    mi_y = min(mi_y, ys[idx])
                    ma_y = max(ma_y, ys[idx])
            
            ans = min(ans, max(ma_x - mi_x, ma_y - mi_y))
    
    print(ans)

T = int(input())
for _ in range(T):
    solve()
