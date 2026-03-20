def II():
    return int(input())
def MI():
    return map(int,input().split())
def LI():
    return list(map(int,input().split()))


t=II()
for _ in range(t):
    n=II()
    a=LI()
    a.sort()
    mn=10**18
    for i in range(n-1):
        mn=min(mn,a[i]^a[i+1])
    print(mn)