def II():
    return int(input())

def I():
    return list(input())
    

s=I()
n=II()
mod=10**9+7
n%=mod
ans=0
cnt=[0]*26
for i in s:
    x=ord(i)-ord('a')
    cnt[x]+=1
    for j in range(x+1,26):
        ans+=cnt[j]
ans=ans*n%mod

for i in range(26):
    for j in range(i):
        ans+=n*(n-1)//2%mod*cnt[i]%mod*cnt[j]%mod
        ans%=mod
print(ans)