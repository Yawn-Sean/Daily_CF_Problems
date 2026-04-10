import bisect
def II():
    return int(input())
def MII():
    return map(int, input().split())
n=II()
y_x=[]
yPx=[]
for _ in range(n):
    x,y=MII()
    if y>=x:
        y_x.append(y-x)
        yPx.append(y+x)

    r=list(range(len(y_x)))
    r.sort(key=lambda x:yPx[x])
    r.sort(key=lambda x:y_x[x])
ls=[]
for i in r:
    if len(ls)==0 or ls[-1]<=yPx[i]:
        ls.append(yPx[i])
    else:
        ls[bisect.bisect_right(ls,yPx[i])]=yPx[i]
print(len(ls))