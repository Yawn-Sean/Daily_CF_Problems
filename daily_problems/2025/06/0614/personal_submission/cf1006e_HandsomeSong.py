import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
def MII():
    return map(int,input().split())
n,q=MII()
p=LII()
children=[[]for _ in range(n+1)]
for i in range(2,n+1):
    children[p[i-2]].append(i)
order=[0]*n
pos=[0]*(n+1)
sz=[0]*(n+1)
timer=0
stack=[(1,0)]
while stack:
    node,state=stack.pop()
    if state==0:
        order[timer]=node
        pos[node]=timer
        timer+=1
        stack.append((node,1))
        for child in reversed(children[node]):
            stack.append((child,0))
    else:
        sz[node]=1
        for child in children[node]:
            sz[node]+=sz[child]
out=[]
for _ in range(q):
    u,k=MII()
    if k>sz[u]:
        print(-1)
    else:
        print(order[pos[u]+k-1])
