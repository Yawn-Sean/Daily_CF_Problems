import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    a = sorted(range(n), key=lambda x: ps[x][1])
    ans = [] # !注意: 用tmp賦值，不然會容易報錯
    def check(tgt: int) -> bool:
        nonlocal ans
        tmp, rest = [], tot_time
        for pi in a:
            if ps[pi][0] < tgt:
                continue
            rest -= ps[pi][1]
            if rest < 0:
                break
            tmp.append(pi + 1)
            if len(tmp) >= tgt:
                if len(ans) < len(tmp):
                    ans = tmp
                return True
        return False
    
    l, r = 0, max(x[0] for x in ps) + 1
    while l < r:
        mid = (l + r + 1) >> 1
        if check(mid):
            l = mid
        else:
            r = mid - 1
    print(l)
    print(l)
    print(*ans)
    
               
for _ in range(1):
    n, tot_time = MII()
    ps = [tuple(MII()) for _ in range(n)]
    solve()