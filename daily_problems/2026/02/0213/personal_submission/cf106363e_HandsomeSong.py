import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
pos=[0]*n
for i in range(n):
    pos[a[i]]=i
diff_k=[0]*(n+2)
diff_b=[0]*(n+2)
L=pos[0]
R=pos[0]
for v in range(1,n+1):
    diff_k[0]+=n-R
    diff_k[L+1]-=n-R
    diff_b[0]+=n-R
    diff_b[L+1]-=n-R
    if L+1 <=R:
        diff_b[L+1]+=(L+1)*(n-R)
        diff_b[R+1]-=(L+1)*(n-R)
    if R+1 <=n-1:
        diff_k[R+1]-=(L+1)
        diff_k[n]+=(L+1)
        diff_b[R+1]+=(L+1)*n
        diff_b[n]-=(L+1)*n
    if v < n:
        L=min(L,pos[v])
        R=max(R,pos[v])
ans=[]
curr_k=0
curr_b=0
for i in range(n):
    curr_k+=diff_k[i]
    curr_b+=diff_b[i]
    ans.append(curr_k*i+curr_b)
print('\n'.join(map(str,ans)))
