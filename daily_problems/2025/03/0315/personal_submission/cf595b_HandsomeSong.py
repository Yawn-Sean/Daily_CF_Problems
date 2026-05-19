import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,k=MII()
a=LII()
b=LII()
mod=10**9+7
p10_k=10**k
ans=1
for i in range(n//k):
    aa=a[i]
    bb=b[i]
    total=(p10_k-1)//aa+1
    if b==0:
        bad=(p10_k//10-1)//aa+1
    else:
        l=bb*p10_k//10
        r=(bb+1)*p10_k//10-1
        bad=r//aa-(l-1)//aa
    valid=total-bad
    ans=ans*valid%mod
print(ans)