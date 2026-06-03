import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
class Factorial:
    def __init__(self,n,mod):
        self.mod=mod
        self.fac=[1]*n
        for i in range(1,n):
            self.fac[i]=self.fac[i-1]*i%mod
        self.ifac=[1]*n
        self.ifac[-1]=pow(self.fac[-1],-1,mod)
        for i in range(n-1,0,-1):
            self.ifac[i-1]=self.ifac[i]*i%mod
    def comb(self,n,k):
        if n<0 or k<0 or k>n:
            return 0
        return self.fac[n]*self.ifac[k]%self.mod*self.ifac[n-k]%self.mod
k,s,t=MII()
m=5*10**6+10
mod=10**9+7
f=Factorial(m,mod)
x, y = divmod(k, t)
if y==0:
    if s%x:
        print(0)
    else:
        print(f.comb(s//x-1,t-1))
    exit()
ans=0
for i in range(1,s+1):
    if (s-(x+1)*i) < 0:
        break
    if (s-(x+1)*i)%x== 0:
        j=(s-(x+1)*i)//x
        if j>0:
            ans+=f.comb(i-1,y-1)*f.comb(j-1,t-y-1)
            ans%=mod
print(ans)