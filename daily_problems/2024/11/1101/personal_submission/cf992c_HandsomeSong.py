import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
mod=10**9+7
x,k=MII()
print((pow(2,k+1,mod)%mod*x%mod-(pow(2,k,mod)-1)%mod)%mod if x else 0)