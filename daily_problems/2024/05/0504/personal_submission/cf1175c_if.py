t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    s=float("inf")
    for i in range(n-k):
        if s>-a[i]+a[i+k]:
            s=-a[i]+a[i+k]
            ans=(a[i]+a[i+k])//2
    print(ans)
