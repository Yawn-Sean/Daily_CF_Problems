import sys
input=sys.stdin.readline
mod=998244353
q=int(input())
queries=[]
max_n=0
for _ in range(q):
    n,k=map(int,input().split())
    queries.append((n,k))
    if n+1>max_n:
        max_n=n+1
fact=[1]*(max_n+1)
for i in range(1,max_n+1):
    fact[i]=fact[i-1]*i%mod
inv_fact=[1]*(max_n+1)
inv_fact[max_n]=pow(fact[max_n],mod-2,mod)
for i in range(max_n,0,-1):
    inv_fact[i-1]=inv_fact[i]*i%mod
out=[]
for n,k in queries:
    if k > n:
        out.append("0")
        continue
    ans=fact[n+1]*inv_fact[k+1]%mod
    ans=ans*inv_fact[n-k]%mod
    print(ans)