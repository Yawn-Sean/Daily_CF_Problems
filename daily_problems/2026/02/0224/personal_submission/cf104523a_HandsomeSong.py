def II():
    return int(input())

def f(x):
    ans=0
    while x:
        ans+=x
        x//=10
    return ans

t=II()
for _ in range(t):
    n=II()
    l,r=1,10**18

    while l<=r:
        mid=(l+r)//2

        if f(mid)>n:
            r=mid-1
        else:
            l=mid+1
    print(n-r)