# Submission link: https://codeforces.com/contest/681/submission/277455723
def main():
    n, m = MII()

    path = [[] for _ in range(n)]
    isroot = [1] * n

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        isroot[v] = 0

    to_get = LGMI()

    used = [0] * n
    for x in to_get:
        used[x] = 1

    ans = [-1] * n
    order = []
    stk = [i for i in range(n) if isroot[i]]
    while stk:
        u = stk.pop()
        if used[u]:
            order.append(u)
            ans[u] = u
        for v in path[u]:
            ans[v] = ans[u]
            stk.append(v)

    if ans != to_get:
        print(-1)
        exit()

    order.reverse()
    print(len(order))
    print('\n'.join(str(x + 1) for x in order))