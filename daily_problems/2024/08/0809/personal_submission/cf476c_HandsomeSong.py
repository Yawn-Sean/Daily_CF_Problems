import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
a,b=MII()
mod=10**9+7
ans=a*(a+1)//2*b+a
ans%=mod
ans*=b*(b-1)//2
ans%=mod
print(ans)