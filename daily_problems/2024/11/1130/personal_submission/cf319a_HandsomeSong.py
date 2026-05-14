import sys
input = sys.stdin.readline
def I():
    return input().strip()
num=[int(x)for x in I()]
n=len(num)
ans=0
mod=10**9+7
for i in range(n):
    if num[i]==1:
        power=2*n-i-2
        ans=(ans+pow(2,power,mod))%mod
print(ans)