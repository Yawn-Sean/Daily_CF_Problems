import sys
input = sys.stdin.readline
def II():
    return int(input())
mod=10**9+7
t=II()
for _ in range(t):
    n=II()
    p=pow(2,n,mod)
    t=((n-3)%mod)*p%mod
    print((t+(n%mod)+3)%mod)