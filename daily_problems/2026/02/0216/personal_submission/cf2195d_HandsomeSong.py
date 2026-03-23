t=int(input())
for _ in range(t):
    n=int(input())
    f=list(map(int,input().split()))
    total=(f[0]+f[-1])//(n-1)#sum(a)
    cur=0
    a=[0]*n
    for i in range(n-1):
        a[i]=(total+f[i+1]-f[i])//2-cur
        cur+=a[i]
    a[-1]=total-cur
    print(' '.join(map(str,a)))