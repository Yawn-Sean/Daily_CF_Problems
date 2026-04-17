def II():
    return int(input())
mod=998244353 
t=II()
for _ in range(t):
    n=II()
    sum=0
    for i in range(1,n+1):
        sum+=1*pow(1+i,-1,mod)
    print((n+1)*sum%mod)