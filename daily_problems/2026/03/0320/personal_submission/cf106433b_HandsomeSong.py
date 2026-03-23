def II():
	return(int(input()))
def MI():
	return(map(int,input().split()))
def LI():
	return(list(map(int,input().split())))

t=II()
for _ in range(t):
	n=II()
	a=LI()
	b=[0]*n
	app=1
	mapping={}
	for i in range(n):
		if a[i] not in mapping:
			mapping[a[i]]=app
			app+=1
		b[i]=mapping[a[i]]
	print(*b)


