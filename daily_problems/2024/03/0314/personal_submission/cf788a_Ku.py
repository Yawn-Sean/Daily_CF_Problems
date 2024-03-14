n = int(input())
a = list(map(int,input().split()))

'''@cache
def dfs(i):
    if i == n - 2 or i == n - 3:
        return abs(a[i] - a[i+1])
    opt = abs(a[i] - a[i+1])
    change = opt - abs(a[i+1]-a[i+2])
    return max(opt,change+dfs(i+2))
print(max(dfs(i) for i in range(n-1)))
dfs.cache_clear()'''
ans = [0] * n
for i in range(n-2,-1,-1):
    if i == n-2 or  i == n - 3:
        ans[i] = abs(a[i] - a[i+1])
    else:
        opt = abs(a[i] - a[i+1])
        change = opt - abs(a[i + 1] - a[i + 2])
        ans[i] = max(opt, change + ans[i+2])
print(max(ans[:-1]))
