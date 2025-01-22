'''
https://codeforces.com/problemset/submission/507/292488565
507C
20241120 Y1
1700
DFS
'''
# ref 
h, n = map(int, input().split())

def dfs(l, r, c, d):
    if d == 0: return 0
    m = l + r >> 1
    ans = 1 << d if (n <= m) == c else 1
    ans += dfs(l, m, 1, d - 1) if n <= m else dfs(m + 1, r, 0, d - 1)
    return ans    

print(dfs(1, 1 << h, 0, h))