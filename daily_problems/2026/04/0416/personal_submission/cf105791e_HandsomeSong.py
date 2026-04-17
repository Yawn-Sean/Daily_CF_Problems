def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def update(x,pi):
    pos=size+x
    diff=100-pi
    val_a=diff*inv100%mod
    val_b=pi*pow(diff,-1,mod)%mod if diff else 0
    tree[pos]=(val_a,val_b)
    pos>>=1
    while pos:
        tree[pos]=(tree[2*pos][0]*tree[2*pos+1][0]%mod,tree[2*pos][1]+tree[2*pos+1][1]%mod)
        pos>>=1
def query(l, r):
    if l > r:
        return (1, 0)
    l += size; r += size
    prod_res, sum_res = 1, 0
    while l <= r:
        if l & 1:
            prod_res = prod_res * tree[l][0] % mod
            sum_res = (sum_res + tree[l][1]) % mod
            l += 1
        if not (r & 1):
            prod_res = prod_res * tree[r][0] % mod
            sum_res = (sum_res + tree[r][1]) % mod
            r -= 1
        l >>= 1; r >>= 1
    return (prod_res, sum_res)
mod=10**9+7
n,q=MII()
p=LII()
inv100=pow(100,mod-2,mod)
size=1
while size<n:
    size<<=1
tree=[(1,0)]*(2*size)
for i in range(n):
    diff=100-p[i]
    val_a=diff*inv100%mod
    val_b=p[i]*pow(diff,-1,mod)%mod if diff else 0
    tree[size+i]=(val_a,val_b)
for i in range(size-1,0,-1):
    tree[i]=(tree[2*i][0]*tree[2*i+1][0]%mod,tree[2*i][1]+tree[2*i+1][1]%mod)

for _ in range(q):
    xp=LII()
    if xp[0]==1:
        update(xp[1]-1,xp[2])
    else:
        prod,s=query(xp[1],n-1)
        print(prod*(1+s)%mod)