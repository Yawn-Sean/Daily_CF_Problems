a,b,n,x = map(int,input().split())
mod = 10**9 +7
ans = pow(a,n,mod)*x
gp = (pow(a,n,mod)-1)*(pow(a-1,mod-2,mod))*b
if(a==1):
    gp = (b*n)%mod
print((ans+gp)%mod)
