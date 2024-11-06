'''
https://codeforces.com/problemset/submission/1280/290174615
1280C
2024/11/6 Y2
2000
graph
'''
#ref 
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    k = int(input())
    n = 2 * k
    
    us = []
    vs = []
    ws = []
    
    g = [[] for _ in range(n)]
    
    for i in range(n - 1):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        
        us.append(u)
        vs.append(v)
        ws.append(w)
        g[u].append(i)
        g[v].append(i)
    return n, us, vs, ws, g

def solve(n, us, vs, ws, g):
    parent = [-1] * n
    parent_weight = [0] * n
    order = []
    stk = [0]
    while stk:
        u = stk.pop()
        order.append(u)
        for i in g[u]:
            v = us[i] + vs[i] - u
            if parent[u] != v:
                parent[v] = u
                parent_weight[v] = ws[i]
                stk.append(v)
    
    sz = [1] * n
    for u in reversed(order):
        if u > 0:
            sz[parent[u]] += sz[u]
    
    mi = ma = 0
    for i in range(n):
        mi += sz[i] % 2 * parent_weight[i]
        ma += min(n - sz[i], sz[i]) * parent_weight[i]
    
    return f'{mi} {ma}'

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)