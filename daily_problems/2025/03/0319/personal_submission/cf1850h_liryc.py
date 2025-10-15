'''
https://codeforces.com/problemset/submission/1850/311347883
'''
# DFS
def solve(n: int, m: int, conditions: list[list[int]]) -> bool:
    for i in range(m):
        a, b, d = conditions[i]
        a, b = a - 1, b - 1
        if d < 0:
            a, b, d = b, a, -d
        conditions[i][:] = a, b, d
    conditions.sort()
    g = [[] for _ in range(n)]
    for i in range(m):
        a, b, d = conditions[i]
        if i:
            a0, b0, d0 = conditions[i - 1]
            if a0 == a and b0 == b:
                if d0 == d:
                    continue
                else:
                    return False
        g[a].append((b, d))
        g[b].append((a, -d))
    pos = [[] for _ in range(n)]

    for i in range(n):
        if not pos[i]:
            pos[i].append(0)
            stk = deque()
            stk.append(i)
            while stk:
                a = stk.pop()
                for b, d in g[a]:
                    p = pos[a][0] + d
                    if not pos[b]:
                        pos[b].append(p)
                        stk.append(b)
                    elif pos[b][0] != p:
                        return False
    return True

