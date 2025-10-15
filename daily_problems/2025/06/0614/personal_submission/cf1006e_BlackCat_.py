import sys
input=lambda:sys.stdin.readline()
n,q=map(int,input().split())
a=list(map(int ,input().split()))
a=[-1]+a
e=[[]for i in range(n)]
for i in range(1,n):
	a[i]-=1
	e[a[i]].append(i)
ans=[]
siz=[1 for i in range(n)]
res=[]
st=[0 for i in range(n)]
sta=[(0,0)]
while sta:
	cur,idx=sta.pop()
	if idx==0:
		res.append(cur)
		st[cur]=len(res)-1
	if idx<len(e[cur]):
		sta.append((cur,idx+1))
		sta.append((e[cur][idx],0))
	else:
		if(a[cur]!=-1):
			siz[a[cur]]+=siz[cur]
for i in range(q):
	l,r=map(int,input().split())
	l-=1
	r-=1
	if r<siz[l]:
		ans.append(res[st[l]+r]+1)
	else:
		ans.append(-1)

print('\n'.join(map(str,ans)))


