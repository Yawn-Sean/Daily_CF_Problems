n,m, k = map(int,input().split())
l = list(map(int,input().split()))
col = [[] for i in range(m+1)]
for i in range(n):
    col[l[i]].append(i)

ans = 0
for i in range(m+1):
    ci = col[i]
    r = 0
    now = 0
    if len(ci) == 1:
        ans = max(ans, 1)
        continue
    for l in range(len(ci)):
        while r+1 < len(ci) and ci[r+1] - ci[r] - 1 + now <= k:
            now += ci[r+1] - ci[r] - 1
            r += 1
        ans = max(ans, r-l+1)
        if l != len(ci)-1:
            now -= ci[l+1] - ci[l] - 1
    
print(ans)
