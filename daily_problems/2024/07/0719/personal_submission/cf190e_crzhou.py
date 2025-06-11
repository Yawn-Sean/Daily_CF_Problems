import sys
input = lambda: sys.stdin.readline().strip()

def MII():
    return map(int, input().split())

def GMI():
    return map(lambda x: int(x) - 1, input().split())


def main():
    n, m = MII()

# 使用 g = defaultdict(list) 会爆内存 !!!
    nodes = []
    last_idx = []
    path = [-1] * n

    def add_edge(u, v):
        last_idx.append(path[u])  # 当前节点上一次出现的位置
        path[u] = len(nodes)
        nodes.append(v)           # 当前节点的邻居

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

if __name__ == "__main__":
    main()

# 有一说一刚刚copy了这个cf190e_hum.py超时了，所以我copy了cf190e_yawn_sean.py(
