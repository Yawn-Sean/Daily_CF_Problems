n,m=MII()
mod =10**6+3
def f (x,k):
    a,b,ans=x,0,1
    while (k>0):
        if (k&(1<<b)):
            ans=(ans*a)%mod
            k^=(1<<b)
        b+=1
        a=(a*a)%mod
    return ans
c=[1] *(n+m+1)
for i in range (2,m+n+1):
    c[i]=c[i-1]*i
    c[i]%=mod
print((c[m+n]*f (c[n],mod -2)*f(c[m],mod -2)-1)%mod )