def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def I():
    return input()
    
t=II()
for _ in range(t):
    sx,sy,tx,ty,k=MII()
    dx=abs(sx-tx)
    dy=abs(sy-ty)
    if dx > dy:
        dx,dy=dy,dx
    if dy<=k*dx+k:
        print(dx+dy)
    else:
        more=(dy-k*dx-k+2*k-1)//(2*k)
        more*=2
        print(dy+dx+more)
