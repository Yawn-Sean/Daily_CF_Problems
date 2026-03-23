def II():
	return(int(input()))
def MI():
	return(map(int,input().split()))
def LI():
	return(list(map(int,input().split())))


def q(i,j):
	print('?',i,j,flush=True)
	return II()


n=II()
ret=[]
for i in range(n):
	ret.append(q(0,i))
if min(ret)==n:
	for i in range(n):
		if q(1,i)==n:
			print('!',i)
			break
else:
	idx=ret.index(n)
	if idx==0:
		ask=1
	else:
		ask=idx-1
	for i in range(n):
		if q(i,ask)==n:
			print('!',(idx-i)%n)
			break
		