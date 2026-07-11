import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
def I():
    return input().strip()
n=II()
g=[[] for _ in range(n+1)]
a=LII()
for i in range(2,n+1):
    p=a[i-2]
    g[p].append(i)
def dfs(f):
    if not f:return []
    pp=[f[0]]+dfs(g[f[0]])
    r1=dfs(f[1:])
    r2=r1[::-1]
    ans=r1[:]
    for i,x in enumerate(pp):
        ans.append(x)
        ans.extend(r2 if i%2==0 else r1)
    return ans
ans=dfs(g[1])
print(len(ans))
if ans:
    print(*ans)