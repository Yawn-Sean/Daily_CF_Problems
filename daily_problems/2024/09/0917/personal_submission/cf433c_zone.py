# submission url: https://codeforces.com/contest/433/submission/281553330
# 单独考虑每个不同的数，用中位数贪心

n, m = map(int, input().split()) 
a = list(map(int, input().split())) 

vs = defaultdict(list)

ans = 0

for i, x in enumerate(a):
    vs[x].append(i)
    if i: 
        ans += abs(a[i] - a[i - 1])

ans_ = ans

for v, idxs in vs.items():
    q = []
    res = res_ = 0 
    for i in idxs: 
        if i and a[i] != a[i - 1]: 
            q.append(a[i - 1])
        if i < m - 1 and a[i] != a[i + 1]: 
            q.append(a[i + 1])
    if len(q) == 0: 
        continue
    q.sort()
    tgt = q[len(q) // 2]
    for x in q: 
        res_ += abs(v - x)
        res += abs(tgt - x)
    
    ans = min(ans, ans_ - res_ + res)
print(ans)
