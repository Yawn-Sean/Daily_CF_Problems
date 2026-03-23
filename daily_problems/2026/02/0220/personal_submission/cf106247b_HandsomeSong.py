def II():
	return(int(input()))
def MI():
	return(map(int,input().split()))
def LI():
	return(list(map(int,input().split())))

n=II()
if n==1:
	print(1)
	print(1)
elif n ==2:
	print(-1)
else:
	print(3*pow(2,n-2))
	print(1,2,*(3*pow(2,i) for i in range(n-2)))