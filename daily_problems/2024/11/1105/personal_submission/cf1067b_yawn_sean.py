# Submission link: https://codeforces.com/contest/1067/submission/289997684
def main():
    n, k = MII()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    dis = [-1] * n
    parent = [-1] * n

    for i in range(n):
        if len(path[i]) == 1:
            dis[i] = 0
            stk = [i]
            
            while stk:
                u = stk.pop()
                for v in path[u]:
                    if dis[v] == -1:
                        dis[v] = dis[u] + 1
                        parent[v] = u
                        stk.append(v)
            
            break

    ma = max(dis)

    dis1 = [-1] * n

    u = dis.index(ma)
    dis1[u] = 0
    stk = [u]

    while stk:
        u = stk.pop()
        for v in path[u]:
            if dis1[v] == -1:
                dis1[v] = dis1[u] + 1
                stk.append(v)

    node = -1
    for i in range(n):
        if dis[i] == k and dis1[i] == k:
            node = i

    if len(path[node]) < 3:
        exit(print('No'))

    to_center = [-1] * n
    to_center[node] = 0

    stk = [node]
    while stk:
        u = stk.pop()
        for v in path[u]:
            if to_center[v] == -1:
                to_center[v] = to_center[u] + 1
                stk.append(v)

    for i in range(n):
        if len(path[i]) == 1:
            if to_center[i] != k:
                exit(print('No'))
        elif i != node and len(path[i]) <= 3:
            exit(print('No'))

    print('Yes')