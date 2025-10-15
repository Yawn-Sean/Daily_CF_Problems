import sys
input=lambda:sys.stdin.readline().strip()

T=int(input())

while T:
    T-=1
    n,x,y=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    a.append(a[0]+n)
    cnt=x
    d=[]
    for i in range(x):
        k=a[i+1]-a[i]
        if k==2:
            cnt+=1
        elif k%2==0:
            d.append(k//2-1)
    d.sort()
    for t in d:
        if y>=t:
            y-=t
            cnt+=t*2+1
        else:
            break
    cnt+=2*y
    res=min(n,cnt)-2
    print(res)
