# Submission Link: https://codeforces.com/contest/1833/submission/268246044
def main():
    n = II()
    us = []
    vs = []
    path = [[] for _ in range(n)]
    
    for i in range(n - 1):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        path[u].append(i)
        path[v].append(i)
    
    parent = [-1] * n
    order = []
    
    stack = [0]
    while stack:
        u = stack.pop()
        order.append(u)
        for i in path[u]:
            v = us[i] ^ vs[i] ^ u
            if v and parent[v] == -1:
                parent[v] = i
                stack.append(v)
    
    size = [1] * n
    ans = []
    for u in reversed(order):
        if u > 0:
            if size[u] == 3:
                ans.append(parent[u])
            else:
                p = us[parent[u]] ^ vs[parent[u]] ^ u
                size[p] += size[u]

    if size[0] == 3:
        return ans
    return -1