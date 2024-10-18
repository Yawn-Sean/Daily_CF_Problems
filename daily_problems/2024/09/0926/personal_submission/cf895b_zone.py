"""
problem url   : https://codeforces.com/problemset/problem/895/B
submission url: https://codeforces.com/contest/895/submission/282990684
"""
n, x, k = MII() 
a = LII() 
a.sort()
cnt, cntv = Counter(), Counter()
ans = 0 

for y in a:
    cnt[(y - 1) // x] += 1 
    ans += cnt[y // x - k]
    if y // x - (y - 1) // x == k: 
        ans += cntv[y]
    cntv[y] += 1 

print(ans)
