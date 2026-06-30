import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
t=II()
for _ in range(t):
    n=II()
    p=[x-1 for x in LII()]
    visited=[False]*n
    ans=0
    odds=[]
    for i in range(n):
        if not visited[i]:
            cycle=[]
            while not visited[i]:
                visited[i]=True
                cycle.append(i+1)
                i=p[i]
            m=len(cycle)
            if m%2==0:
                ans+=abs(sum(cycle[::2])-sum(cycle[1::2]))
            else:
                curr=0
                for j in range(m):
                    curr+=cycle[j] if j%2==0 else -cycle[j]
                best=curr
                for j in range(m):
                    curr=2*cycle[j]-curr
                    if curr > best: best=curr
                odds.append(best)
    odds.sort(reverse=True)
    for i, val in enumerate(odds):
        ans += val if i % 2 == 0 else -val
    print(ans)
