def II():
    return int(input())
def MII():
    return map(int, input().split())
inf=10**20
t=II()
for _ in range(t):
    n,a,b=MII()
    s=[int(c) for c in input()]

    dp0,dp1 =b, inf
    for c in s:
        if c:
            dp0,dp1=inf,dp1+a+2*b
        else:
            dp0,dp1=min(dp0+a+b,dp1+2*a+b),min(dp1+a+2*b,dp0+2*a+2*b)
    print(dp0)

