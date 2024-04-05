import sys

input=lambda: sys.stdin.readline().strip()

n,m=map(int,input().split())
q=list(map(int,input().split()))

res=0.0

for _ in range(m):
    a,b,c=map(int,input().split())
    d=(q[a-1]+q[b-1])/c
    res=max(res,d)

print(res)
