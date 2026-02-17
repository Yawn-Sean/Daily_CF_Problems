'''
2026/2/17 Y1
1500
'''
# tree dp
from sys import stdin
input = lambda: stdin.readline().strip()
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
# pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y

def init():
    n = int(input())
    tg = [[] for _ in range(n + 1)]
    tg[0].append(1)
    for i in range(1, n + 1):
        l, r = map(int, input().split())
        if l == r == 0:
            pass
        else:
            tg[i][:] = l, r
    return n, tg

def solve(n: int, tg: list[list[int]]):
    MOD = 1000000007
    qu = [0]
    pr = [-1] * (n + 1)
    for u in qu:
        for v in tg[u]:
            pr[v] = u
            qu.append(v)

    ans = [0] * (n + 1)
    
    for i in reversed(qu):
        if tg[i] and i > 0:
            u, v = tg[i]
            ans[i] = (ans[u] + 2 + ans[v] + 2) % MOD
    
    for i in qu:
        for j in tg[i]:
            ans[j] += ans[i] + 1
            ans[j] %= MOD
    
    return ans[1:]

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(*ans)
