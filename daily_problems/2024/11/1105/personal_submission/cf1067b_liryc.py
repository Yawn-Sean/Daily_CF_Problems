'''
https://codeforces.com/problemset/submission/1067/290025299
1067B
2024/11/5 Y1
1800
graph
'''
# ref
def solve():
    n, k = map(int, input().split())
    ug = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        ug[u].append(v)
        ug[v].append(u)

    dis = [-1] * n
    parent = [-1] * n

    for i in range(n):
        if len(ug[i]) == 1:
            dis[i] = 0
            stk = [i]
            while stk:
                u = stk.pop()
                for v in ug[u]:
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
        for v in ug[u]:
            if dis1[v] == -1:
                dis1[v] = dis1[u] + 1
                stk.append(v)

    node = -1
    for i in range(n):
        if dis[i] == k and dis1[i] == k:
            node = i

    if len(ug[node]) < 3:
        return 'No'

    to_center = [-1] * n
    to_center[node] = 0

    stk = [node]
    while stk:
        u = stk.pop()
        for v in ug[u]:
            if to_center[v] == -1:
                to_center[v] = to_center[u] + 1
                stk.append(v)

    for i in range(n):
        if len(ug[i]) == 1:
            if to_center[i] != k:
                return 'No'
        elif i != node and len(ug[i]) <= 3:
            return 'No'

    return 'Yes'

if __name__ == '__main__':
    ans = solve()
    print(ans)