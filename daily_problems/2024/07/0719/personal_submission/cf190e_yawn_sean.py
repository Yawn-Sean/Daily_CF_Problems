# Submission Link: https://codeforces.com/contest/190/submission/271301569
def main():
    n, m = MII()

    nodes = []
    last_idx = []
    path = [-1] * n

    def add_edge(u, v):
        last_idx.append(path[u])
        path[u] = len(nodes)
        nodes.append(v)

    def neighbors(u):
        cur = path[u]
        while cur >= 0:
            yield nodes[cur]
            cur = last_idx[cur]

    for _ in range(m):
        u, v = GMI()
        add_edge(u, v)
        add_edge(v, u)

    ans = []
    to_search = set(range(n))

    while to_search:
        u = to_search.pop()
        stk = [u]
        component = []
        while stk:
            u = stk.pop()
            component.append(u)
            new_to_search = set()
            for v in neighbors(u):
                if v in to_search:
                    to_search.remove(v)
                    new_to_search.add(v)
            for x in to_search:
                stk.append(x)
            to_search = new_to_search
        ans.append(str(len(component)) + ' ' + ' '.join(str(x + 1) for x in component))

    print(len(ans))
    print('\n'.join(ans))