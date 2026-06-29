import sys
input=sys.stdin.readline
def II():return int(input())
def LII():return list(map(int,input().split()))
n=II()
a=LII()
S=sum(a)
if S%2!=0:
    print(-1)
    exit()
T=S//2
dp=[-1]*(T+1)
dp[0]=-2
for i in range(n):
    x=a[i]
    for s in range(T,x-1,-1):
        if dp[s]==-1 and dp[s-x]!=-1:
            dp[s]=i
if dp[T]==-1:
    print(-1)
    exit()
inA=[False]*n
c=T
while c>0:
    idx=dp[c]
    inA[idx]=True
    c-=a[idx]
A=[]
B=[]
for i in range(n):
    if inA[i]:
        A.append(a[i])
    else:
        B.append(a[i])
A.sort()
B.sort()
res=[]
i=j=0
sa=sb=0
la=len(A)
lb=len(B)
while i<la or j<lb:
    if sa<=sb:
        res.append(A[i])
        sa+=A[i]
        i+=1
    else:
        res.append(B[j])
        sb+=B[j]
        j+=1
print(*res)
