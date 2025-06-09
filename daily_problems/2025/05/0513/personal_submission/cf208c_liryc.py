'''
https://codeforces.com/problemset/submission/208/319462295
'''
# bfs
def solve(n: int, m: int, edges: list[list[int]]) -> float:
    ug = [[] for _ in range(n)]
    for u, v in edges:
        ug[u - 1].append(v - 1)
        ug[v - 1].append(u - 1)
    v0 = [-1] * n
    v0[0] = 0
    d0 = [-1] * n
    d0[0] = 1
    dq = deque()
    dq.append(0)
    while dq:
        s = dq.popleft()
        for t in ug[s]:
            if v0[t] < 0:
                v0[t] = v0[s] + 1
                d0[t] = d0[s]
                dq.append(t)
            elif v0[t] == v0[s] + 1:
                d0[t] += d0[s]

    vn = [-1] * n
    vn[n - 1] = 0 
    dn = [-1] * n
    dn[n - 1] = 1 
    dq.append(n - 1)
    while dq:
        s = dq.popleft()
        for t in ug[s]:
            if vn[t] < 0:
                vn[t] = vn[s] + 1
                dn[t] = dn[s]
                dq.append(t)
            elif vn[t] == vn[s] + 1:
                dn[t] += dn[s]
    ans = 1.0
    for u in range(1, n - 1):
        if v0[u] + vn[u] == v0[n - 1]:
            ans1 = d0[u] * dn[u] * 2 / d0[n - 1]
            if ans1 > ans:
                ans = ans1
    return ans
