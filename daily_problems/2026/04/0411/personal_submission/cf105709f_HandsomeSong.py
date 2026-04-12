def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
n,k=MII()
b=LII()
w=LII()
v=LII()
diff=[0]*(k+2)
for i in range(n):
    if b[i]+w[i]<=k:
        l=b[i]
        r=k-w[i]
        diff[l]+=v[i]
        diff[r+1]-=v[i]
mx=0
cur=0
for i in range(k+1):
    cur+=diff[i]
    mx=max(mx,cur)
print(mx)