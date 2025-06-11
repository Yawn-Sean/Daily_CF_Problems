import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

# Key: 特別平面，可以分開考慮x,y,z
# WA:1, time:30min, dt:20250111
def solve():
    ans = 0
    if x > x1:
        ans += a[5]
    elif x < 0:
        ans += a[4]
    
    if y > y1:
        ans += a[1]
    elif y < 0:
        ans += a[0]
    
    if z > z1:
        ans += a[3]
    elif z < 0:    
        ans += a[2]
    
    print(ans)
               
for _ in range(1):
    x, y, z = MII()
    x1, y1, z1 = MII()
    a = list(MII())
    solve()