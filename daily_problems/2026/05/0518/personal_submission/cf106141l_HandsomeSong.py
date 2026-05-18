import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
indices=sorted(range(n),key=lambda i: -abs(a[i]))
total=sum(abs(x) for x in a)
val=n
best_total=total
best_val=val
best_k=0
for k in range(n):
    idx=indices[k]
    total+=2*abs(a[idx])
    val+=8
    if total*total*best_val>best_total*best_total*val:
        best_total=total
        best_val=val
        best_k=k+1
ans=[0]*n
for i in range(n):
    d=3 if i<best_k else 1
    idx=indices[i]
    if a[idx]>=0:
        ans[idx]=d
    else:
        ans[idx]=-d
print(*ans)