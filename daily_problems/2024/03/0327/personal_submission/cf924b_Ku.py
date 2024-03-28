import bisect
n, u = map(int,input().split())
E = list(map(int,input().split()))
ans = 0
for j in range(1,n-1):
    i = j-1
    x = E[i] + u
    k = bisect.bisect_right(E,x)
    if k - 1 <= j:
        continue
    else:
        res = (E[k-1] - E[j]) / (E[k-1] - E[i])
        ans = max(ans,res)
print(ans if ans > 0 else -1)
