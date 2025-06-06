n, m = MII()
a = LII()
b = LII()
s = set()
cnt = defaultdict(int)
for i in range(m):
    if b[i]:
        s.add(i + 1)
        cnt[i + 1] = b[i]

i = j = 0
tmp = 0
ans = inf
while i < n:
    while j < n and tmp < len(s):
        if a[j] in s:
            cnt[a[j]] -= 1
            if cnt[a[j]] == 0:
                tmp += 1
        j += 1
    if tmp < len(s):
        break
    ans = fmin(ans, j - i)
    if a[i] in s:
        cnt[a[i]] += 1
        if cnt[a[i]] == 1:
            tmp -= 1
    i += 1
    
print((ans - sum(b)) if ans != inf else -1)
