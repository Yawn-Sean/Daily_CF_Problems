import math
n,c,d=map(int,input().split())
cc=[]
dd=[]
for _ in range(n):
    b,p,k=map(str,input().split())
    p=int(p)
    b=int(b)
    if k=="C":
        cc.append([b,p])
    else:
        dd.append([b,p])
n=len(cc)
m=len(dd)
wc=[]
wd=[]
vc=[]
vd=[]
c1=[i[0] for i in cc if i[1]<=c]
d1=[i[0]for i in dd if i[1]<=d]
ans1=0
if c1 and d1:
    ans1+=max(c1)+max(d1)
cc.sort(key=lambda x:x[1])
dd.sort(key=lambda x:x[1])
for i in range(n):
    vc.append(cc[i][0])
    wc.append(cc[i][1])
for i in range(m):
    vd.append(dd[i][0])
    wd.append(dd[i][1])
vvc=vc[:]
vvd=vd[:]

for i in range(1,n):
    vc[i]=max(vc[i-1],vc[i])
for i in range(1,m):
    vd[i]=max(vd[i-1],vd[i])
ans2=0
for i in range(n-1,0,-1):
    if c-wc[i]-wc[0]<0:
        continue
    left=0
    right=i-1
    while left<right:
        mid=math.ceil((left+right)/2)
        if wc[mid]<=c-wc[i]:
            left=mid
        else:
            right=mid-1

    ans2=max(ans2,vvc[i]+vc[left])
ans3=0
for i in range(m-1,0,-1):
    if d-wd[i]-wd[0]<0:
        continue
    left=0
    right=i-1
    while left<right:
        mid=math.ceil((left+right)/2)
        if wd[mid]<=d-wd[i]:
            left=mid
        else:
            right=mid-1
    ans3=max(ans3,vvd[i]+vd[left])
print(max(ans1,ans2,ans3))
