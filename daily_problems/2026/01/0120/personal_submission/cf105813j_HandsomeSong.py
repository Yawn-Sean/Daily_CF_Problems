def II():
    return int(input())
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
mod=10**9+7
t=II()
for _ in range(t):
    n,k=MII()
    a=LII()
    print(sum(a)*pow(n,mod-2,mod)%mod)
