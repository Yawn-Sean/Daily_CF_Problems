def II():
    return int(input())
def MFI():
    return map(float, input().split())
q=II()
for _ in range(q):
    p,r,y=MFI()
    c=(p+r+y)/2
    a1=0
    a2=c
    a3=r
    a4=c-p
    mn=min(a1,a2,a3,a4)
    mx=max(a1,a2,a3,a4)
    k=(mn+mx)/2
    n=k
    e=c-k
    s=k-r
    w=c-k-p
    print(n,e,s,w)

