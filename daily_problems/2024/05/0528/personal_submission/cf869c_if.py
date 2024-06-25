a,b,c=map(int,input().split())
M=998244353
def C(x, y):
	z,t=0, 1
	for i in range(min(x,y)+1):
		z+=t
		t*=(x-i)*(y-i)*pow(i+1,M-2,M)%M
	return z
print(C(a,b)*C(a,c)*C(b,c)%M)
