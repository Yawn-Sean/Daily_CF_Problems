from math import gcd
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()

g=gcd(*a)
for i in range(n):
    a[i]//=g

mx=max(a)
pf=list(range(mx+1))
for i in range(2,mx+1):
    if pf[i]==i:
        for j in range(i,mx+1,i):
            pf[j]=i

pp=[0]*(mx+1)
for x in a:
    while x>1:
        p=pf[x]
        if pp[p]==1:
            print('NO')
            exit()
        pp[p]=1
        while x%p==0:
            x//=p
print('YES')
    