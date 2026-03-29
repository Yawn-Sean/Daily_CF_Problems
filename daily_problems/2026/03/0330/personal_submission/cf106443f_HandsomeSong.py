t=int(input())
mod=10**9+7
for _ in range(t):
    n=int(input())
    down=(n-1)*(n-2)//2%mod
    up=n//2*(n//2-1)//2*3%mod
    print((down-up)*pow(down,-1,mod)%mod)
