import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,q,c=MII()
cnt=[[[0]*(c+1) for _ in range(101)] for _ in range(101)]
for _  in range(n):
    x,y,z=MII()
    cnt[x][y][z]+=1
for x in range(1,101):
    for y in range(1,101):
        for b in range(c+1):
            cnt[x][y][b]+=cnt[x-1][y][b]+cnt[x][y-1][b]-cnt[x-1][y-1][b]
for _ in range(q):
    t,x1,y1,x2,y2=MII()
    total=0
    for b in range(c+1):
        count=(cnt[x2][y2][b]-cnt[x1-1][y2][b]-cnt[x2][y1-1][b]+cnt[x1-1][y1-1][b])
        if count==0:
            continue
        bt=(b+t)%(c+1)
        total+=count*bt
    print(total)
