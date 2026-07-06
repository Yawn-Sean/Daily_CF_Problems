import sys
from collections import deque
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m=MII()
a=[0]+LII()
adj=[[]for _ in range(n+1)]
for _ in range(m):
    u,v=MII()
    adj[u].append(v)
    adj[v].append(u)
comp=[[0]*(n+1)for _ in range(30)]
for c in range(30):
    mask=1<<c
    cid=0
    for s in range(1,n+1):
        if (a[s]&mask)and comp[c][s]==0:
            cid+=1
            q=deque([s])
            comp[c][s]=cid
            while q:
                u=q.popleft()
                for v in adj[u]:
                    if (a[v]&mask)and comp[c][v]==0:
                        comp[c][v]=cid
                        q.append(v)
for i in range(1,n+1):
    row=[]
    for j in range(1,n+1):
        ok=False
        for c in range(30):
            if comp[c][i]!=0 and comp[c][i]==comp[c][j]:
                ok=True
                break
        row.append('1'if ok else'0')
    print(''.join(map(str,row)))