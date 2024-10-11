"""
problem url   : https://codeforces.com/problemset/problem/975/D
submission url: https://codeforces.com/contest/975/submission/283000631
"""

n, a, b = MII() 
ans = 0 
cnt = Counter()
cntv = Counter()

for _ in range(n):
    x, vx, vy = MII() 
    if vy - vx * a in cnt:
        ans += cnt[vy - vx * a] - cntv[(vx, vy)]
    cnt[vy - vx * a] += 1
    cntv[(vx, vy)] += 1 

print(ans * 2) 
