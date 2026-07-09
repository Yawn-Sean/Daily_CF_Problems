import sys
input = sys.stdin.readline
def II():
    return int(input())
n=II()
mod=10**9+7
if n==1:
    print(1)
elif n==2:
    print(3)
else:
    fib=[0]*(n+4)
    fib[1]=1
    for i in range(2,n+4):
        fib[i]=(fib[i-1]+fib[i-2])%mod
    print((fib[n+3]-2)%mod)