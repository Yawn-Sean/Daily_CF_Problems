import sys
input = sys.stdin.readline
def II():
    return int(input())
n=II()
mod=998244353
if n==1:
    print(pow(2,-1,mod))
else:
    fib=[0]*(n+2)
    fib[1]=1
    fib[2]=1
    for i in range(3,n+1):
        fib[i]=(fib[i-1]+fib[i-2])%mod
    ans=fib[n]*pow(pow(2,n,mod),-1,mod)%mod
    print(ans)
