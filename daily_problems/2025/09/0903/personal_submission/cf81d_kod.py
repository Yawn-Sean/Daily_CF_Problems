n, m = il()
a = il()
cm = n // 2
aa = [(i + 1, min(cm, x)) for i, x in enumerate(a)]
if sum(x for _,x in aa) < n:
    print(-1)
    exit()
aa.sort(key=lambda x: -x[1])
res = sum(([i] * x for i, x in aa), [])
ans = [0] * n
pt = 0
for x in res:
    ans[pt] = x
    pt += 2
    if pt >= n:
        pt = 1
print(*ans)




