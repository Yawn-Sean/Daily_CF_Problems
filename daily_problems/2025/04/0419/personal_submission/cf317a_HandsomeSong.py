import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
x,y,m=MII()
if x>=m or y>=m:
    print(0)
elif x<=0 and y<=0:
    print(-1)
else:
    ans=0
    if x<=0:
        ans+=(y-x-1)//y
        x+=ans*y
    if y<=0:
        ans+=(x-y-1)//x
        y+=ans*x
    while x<m and y<m:
        if x>y:
            x,y=y,x
        x+=y
        ans+=1
    print(ans)