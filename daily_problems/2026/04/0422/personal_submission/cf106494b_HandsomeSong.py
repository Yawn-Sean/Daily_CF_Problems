def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
l=LII()
r=LII()
idx=l.index(max(l))
ans=[0]*n
s=0
for i in range(n):
    ans[i]=min(l[idx],r[i])
    s+=ans[i]
if 2*l[idx]<=s:
    print(*ans)
else:
    print(-1)