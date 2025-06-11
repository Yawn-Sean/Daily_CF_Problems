# 从叶子出发往跟给特定的人排序
# 若 B 是 A 的祖先，且 B 和 A 有不同的目标，必有 A 的目标不在 B 的 上面
'''
于是 若某个点是 期望结点，那么无论如何 都要选中自己，否则选择和自己父节点相同
这样每个点选的结点 一定是它祖先选的最低期望结点，这样构造一定唯一且没有冲突
于是再和原来的 需求比对 判断是否合法
'''


def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    ancs = [-1 for _ in range(n)]
    for i in range(m):
        u, v = map(lambda x: int(x)-1, input().split())
        g[u].append(v)
        ancs[v] = u

    aims = list(map(lambda x: int(x)-1, input().split()))
    vis = [0 for _ in range(n)]
    ans = [0 for _ in range(n)]

    for x in aims:
        vis[x] = 1
    stk = [i for i in range(n) if ancs[i] == -1]
    order = []
    while stk:
        u = stk.pop()
        if vis[u]:
            ans[u] = u
            order.append(u)
        for v in g[u]:
            ans[v] = ans[u]
            stk.append(v)

    if ans != aims:
        print(-1)
        return
    order.reverse()
    print(len(order))
    print('\n'.join(str(x+1) for x in order))
