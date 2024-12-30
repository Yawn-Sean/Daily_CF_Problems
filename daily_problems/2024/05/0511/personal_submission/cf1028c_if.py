n=int(input())
x1=[]
y1=[]
x2=[]
y2=[]
for _ in range(n):
    x11,y11,x22,y22=map(int,input().split())
    x1.append(x11)
    y1.append(y11)
    x2.append(x22)
    y2.append(y22)
prex1=x1.copy()
prex2=x2.copy()
prey1=y1.copy()
prey2=y2.copy()
for i in range(1,n):
    prex1[i]=max(prex1[i],prex1[i-1])
    prey1[i]=max(prey1[i],prey1[i-1])
    prex2[i]=min(prex2[i],prex2[i-1])
    prey2[i]=min(prey2[i],prey2[i-1])
sufx1=x1.copy()
sufx2=x2.copy()
sufy1=y1.copy()
sufy2=y2.copy()
for i in range(n-2,-1,-1):
    sufx1[i]=max(sufx1[i],sufx1[i+1])
    sufy1[i]=max(sufy1[i],sufy1[i+1])
    sufx2[i]=min(sufx2[i],sufx2[i+1])
    sufy2[i]=min(sufy2[i],sufy2[i+1])
for i in range(n):
    if i==0:
        max_x1=sufx1[i+1]
        max_y1=sufy1[i+1]
        min_x2=sufx2[i+1]
        min_y2=sufy2[i+1]
    elif i==n-1:
        max_x1=prex1[-2]
        max_y1=prey1[-2]
        min_x2=prex2[-2]
        min_y2=prey2[-2]
    else:
        max_x1=max(sufx1[i+1],prex1[i-1])
        max_y1=max(sufy1[i+1],prey1[i-1])
        min_x2=min(sufx2[i+1],prex2[i-1])
        min_y2=min(sufy2[i+1],prey2[i-1])
    if max_x1<=min_x2 and max_y1<=min_y2:
        print(max_x1,max_y1)
        break
