'''
https://codeforces.com/gym/106363/submission/362715626
2026/2/13 Y1
1600
'''
# prefix and suffix sum
# 前后缀分解，包含i的=全部-不包含i的=全部-pre(i-1)-suf(i+1)
from sys import stdin
input = lambda: stdin.readline().strip()
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
# pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]) -> list[int]:
    pres, ps = [0] * n, [0] * n
    vis = [-1] * n
    for i in range(n):
        x = a[i]
        vis[x] = x
        if x < n - 1 and vis[x + 1] >= 0:
            vis[x] = vis[x + 1]
        if x and vis[x - 1] >= 0:
            vis[x - 1] = vis[x]
        mex = 0
        if vis[mex] >= 0:
            v = mex
            stk = []
            while vis[v] != v:
                stk.append(v)
                v = vis[v]
            for u in stk:
                vis[u] = v
            mex = v + 1
        ps[i] = mex
        if i:
            ps[i] += ps[i - 1]

    # all mex sum of [0..i]
    for i in range(n):
        pres[i] = ps[i]
        if i:
            pres[i] += pres[i - 1]
    # all mex sum of [i..n-1]
    sufs = ps # just reuse the memory
    for i in range(n):
        sufs[i] = pres[-1]
        if i:
            sufs[i] -= pres[i - 1]

    # the sum includes i = all sum - pres[i - 1] - sufs[i + 1]
    ans = vis # just reuse the memory
    for i in range(n):
        ans[i] = pres[-1]
        if i:
            ans[i] -= pres[i - 1]
        if i < n - 1:
            ans[i] -= sufs[i + 1]

    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(*ans, sep='\n')
