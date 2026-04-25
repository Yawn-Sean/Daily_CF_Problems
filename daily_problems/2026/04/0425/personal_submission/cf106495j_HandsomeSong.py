t=int(input())
mod=10**9+7
for _ in range(t):
    n=int(input())
    if n<3:
        print(0)
        continue
    even=n//2
    odd=(n+1)//2
    print((even*(even-1)*(even-2)//6%mod+even*odd*(odd-1)//2%mod)%mod)
