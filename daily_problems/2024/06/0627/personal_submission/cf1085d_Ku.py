n,s = RII()
cnt = Counter()
for _ in range(n-1):
    a,b = RII()
    cnt[a] += 1
    cnt[b] += 1
ans = 0
for k,v in cnt.items():
    if v == 1:
        #叶子节点
        ans += 1

print(s / ans * 2)
