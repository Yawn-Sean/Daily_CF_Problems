def II():
	return(int(input()))
def MI():
	return(map(int,input().split()))
def LI():
	return(list(map(int,input().split())))
t=II()
for _ in range(t):
	n=II()
	s=list(input())
	cnt=0
	flag=0
	for i in range(n):
		if s[i]!='?':
			cnt+=1
			cnt+=flag
			flag=0
		elif i and s[i-1]!='?':
			if i+1<n and s[i+1]!='?' and s[i-1]!=s[i+1]:
				cnt+=1
			elif i+1< n and s[i+1] =='?':
				flag=1
	print(cnt)