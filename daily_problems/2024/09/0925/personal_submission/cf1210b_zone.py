"""
problem url   : https://codeforces.com/problemset/problem/1210/B
submission url: https://codeforces.com/contest/1210/submission/282853166
"""

n = II() 
a = LII() 
b = LII() 

cnt = defaultdict(int)
for x in a: 
    cnt[x] += 1 
used = [0] * n 
ans = 0

for x, c in cnt.items():
    if c < 2: continue
    for i, [y, v] in enumerate(zip(a, b)):
        if not used[i] and x & y == y:  # 子集
            ans += v 
            used[i] = 1

print(ans)
