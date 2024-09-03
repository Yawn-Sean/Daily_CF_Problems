n,k = RII()
ans =  list(range(1,n+1))
if k % 2 == 0:
    print(-1)
    exit()
k //= 2
def dfs(l,r):
    global k
    if k == 0 or l + 1 == r: return
    mid = (l + r) // 2
    ans[mid],ans[mid - 1] = ans[mid - 1],ans[mid]     
    k -= 1
    dfs(l,mid)
    dfs(mid,r)
dfs(0,n)
res = ' '.join(map(str,ans))
print(-1 if k > 0 else res)
