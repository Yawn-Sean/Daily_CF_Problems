def II():
	return(int(input()))
def MI():
	return(map(int,input().split()))
def LI():
	return(list(map(int,input().split())))


def query(a,b):
	print('?',a,b,flush=True)
	return int(list((input().split()))[1])
def ans(a):
	print('!',a,flush=True)
	return input()

def solve(x):
	if x & -x ==x:
		return(query(x,x)//2)
	y=1 << x.bit_length()
	return query(y-x,x)-solve(y-x)
n=II()
s=LI()
for x in s:
	ans(solve(x))