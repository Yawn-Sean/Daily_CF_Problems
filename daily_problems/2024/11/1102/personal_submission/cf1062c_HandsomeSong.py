import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
mod=10**9+7
n,q=MII()
s=LI()
pref = [0] * (n + 1)
for i in range(n):
    pref[i + 1] = pref[i] + (1 if s[i] == '0' else 0)
for _ in range(q):
    l,r=MII()
    c0=pref[r]-pref[l-1]
    print((pow(2,r-l+1,mod)-pow(2,c0,mod)+mod)%mod)