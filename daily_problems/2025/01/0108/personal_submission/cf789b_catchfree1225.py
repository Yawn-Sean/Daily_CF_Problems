import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

# WA: 3, time: 1hr, dt: 20250108
def solve():
    if abs(b1) > l:
        print(0)
        return
    
    if b1 == 0 or q == 0:
        if 0 not in a:
            print('inf')
        else:
            print(int(b1 not in a))
        return
        
    if q == 1:
        if b1 not in a:
            print('inf')
        else:
            print(0)
        return 
    
    if q == -1:
        ans = [x for x in (b1, -b1) if x not in a]  
        if len(ans) > 0:
            print('inf')
        else:
            print(0)
        return    
    
    x, ans = b1, 0
    while abs(x) <= l:
        if x not in a:
            ans += 1
        x *= q
    print(ans)
               
for _ in range(1):
    b1, q, l, m = MII()
    a = set(MII())
    solve()