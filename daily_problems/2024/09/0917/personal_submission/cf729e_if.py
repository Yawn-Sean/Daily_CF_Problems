inf = float("inf")
n, s = map(int, input().split())
s -= 1
a = list(map(int, input().split()))
cnt = [0] * n
c = 0
for i in range(n):
    if a[i] > n - 1:
        c += 1
    elif i == s:
        if a[i] != 0:
            c += 1
        else:
            cnt[0] += 1
    else:
        if a[i] == 0:
            c += 1
        else:
            cnt[a[i]] += 1
pre = [0] * n
for i in range(n):
    if cnt[i] == 0:
        pre[i] = 1
for i in range(1, n):
    pre[i] += pre[i - 1]
suf = cnt[:]
for i in range(n - 2, -1, -1):
    suf[i] += suf[i + 1]
ans = inf 
suf.append(0)
for i in range(n):
    unsure = c
    unsure += suf[i + 1]
    unsure = max(unsure, pre[i])
    ans = min(ans, unsure)
print(ans)
    
