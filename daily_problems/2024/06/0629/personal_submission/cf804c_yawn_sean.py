# Submission Link: https://codeforces.com/contest/804/submission/267934967
def main():
    n, m = MII()
    ice_creams = [[] for _ in range(n)]

    for i in range(n):
        _, *ice_creams[i] = GMI()

    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    used = [0] * m
    ans = [-1] * m

    vis = [0] * n

    stack = [0]

    while stack:
        u = stack.pop()
        vis[u] = 1
        
        for i in ice_creams[u]:
            if ans[i] != -1:
                used[ans[i]] = 1
        
        pt = 0
        for i in ice_creams[u]:
            if ans[i] == -1:
                while used[pt]: pt += 1
                ans[i] = pt
                used[pt] = 1
        
        for i in ice_creams[u]:
            used[ans[i]] = 0
        
        for v in path[u]:
            if not vis[v]:
                stack.append(v)

    for i in range(m):
        if ans[i] == -1: ans[i] = 1
        else: ans[i] += 1

    print(max(ans))
    print(' '.join(map(str, ans)))