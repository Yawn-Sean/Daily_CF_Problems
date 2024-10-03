# Submission link: https://codeforces.com/contest/1131/submission/284101768
def main():
    n, m = MII()
    grid = [I() for _ in range(n)]

    union = UnionFind(n + m)

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '=':
                union.merge(i, n + j)

    path = [[] for _ in range(n + m)]
    indegs = [0] * (n + m)

    for i in range(n):
        for j in range(m):
            u = union.find(i)
            v = union.find(j + n)
            
            if grid[i][j] == '<':
                path[u].append(v)
                indegs[v] += 1
            elif grid[i][j] == '>':
                path[v].append(u)
                indegs[u] += 1

    stk = []
    ans = [0] * (n + m)

    for i in range(n + m):
        if indegs[i] == 0:
            stk.append(i)
            ans[i] = 1

    cnt = 0
    while stk:
        u = stk.pop()
        cnt += 1
        for v in path[u]:
            ans[v] = fmax(ans[v], ans[u] + 1)
            indegs[v] -= 1
            if indegs[v] == 0:
                stk.append(v)

    if cnt < n + m:
        print('No')
    else:
        print('Yes')
        print(' '.join(str(ans[union.find(i)]) for i in range(n)))
        print(' '.join(str(ans[union.find(n + i)]) for i in range(m)))