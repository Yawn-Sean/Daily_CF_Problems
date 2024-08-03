"""
question url  : https://codeforces.com/problemset/problem/1168/B
submission url: https://codeforces.com/contest/1168/submission/262954223
"""

def solve():
    s = input()
    n = len(s)
    vis = [set() for _ in range(11)]
    for i in range(11):
        for j in range(1 << i): 
            t = bin(j)[2:].zfill(i)
            flag = False
            for l in range(i):
                for r in range(l + 2, i):
                    if (r - l) & 1 == 0 and t[l] == t[r] == t[(r + l) // 2]:
                        flag = True 
            if flag: vis[i].add(t)
    ans = 0
    for l in range(n):
        for r in range(l + 2, min(n, l + 13)):
            if s[l: r + 1] in vis[r - l + 1]: 
                ans += n - r 
                break 
    print(ans)
solve()
