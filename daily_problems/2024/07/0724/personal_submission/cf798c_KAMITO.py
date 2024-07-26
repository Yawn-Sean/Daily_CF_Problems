from functools import reduce
from math import gcd
def solve():
    n=int(input())
    a=list(map(int,input().split()))
    if reduce(gcd,a)>1:
        print('YES\n0')
        return  
    ans=0
    for i in range(n-1):
        if a[i]%2==0:
            continue
        x=2-a[i+1]%2
        ans+=x
        for j in range(x):
            a[i],a[i+1]=a[i]-a[i+1],a[i]+a[i+1]
    if a[n-1]%2:
        ans+=2
    print('YES')
    print(ans)


    return


test=1
# test=int(input())
for _ in range(test):
    solve()
