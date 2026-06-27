import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,x,y=MII()
mod=10**9+7
mx=n-x
e=[0]*(n+2)
for t in range(mx-1,-1,-1):
    new=[0]*(n+2)
    lo=x+t+1
    for j in range(lo,n):
        new[j]=(1+pow(2,-1,mod)*(e[j-1]+e[j+1]))%mod
    new[n]=(1+e[n-1])%mod
    e=new
print(e[y])