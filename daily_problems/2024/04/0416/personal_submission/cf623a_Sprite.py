from collections import Counter
n, m = map(int, input().split())
connec = [[] for _ in range(n)]
ind = [0] * n
for _ in range(m):
    u, v = map(lambda x: int(x)-1, input().split())
    ind[u] += 1
    ind[v] += 1
    connec[u].append(v)
    connec[v].append(u)

def dfs(now, x, k):
    graph[now] = x
    size = 1
    can = True
    for i in connec[now]:
        if graph[i]:
            continue
        if ind[i] != k:
            can = False
        new_size, new_can = dfs(i ,x, k)
        can = can and new_can
        size += new_size
    return (size, can)

x = Counter(ind)
if n == 1:
    print('Yes')
    print('a')
elif len(x) > 3:
    print('No')
else:
    graph = [''] * n
    b = max(x.keys())
    size_b = x[b]
    del x[b]
    if b != n-1:
        go = True
        now = 0
        size_b = 0
    else:
        for i in range(n):
            if ind[i] == b:
                graph[i] = 'b'
        go = False
        for i in range(n):
            if not graph[i]:
                now = i
                go = True
    if not go:
        print('Yes')
        print(''.join(graph))
    else:
        size_a, can = dfs(now, 'a', ind[now])
        if not can or ind[now] != size_b + size_a - 1:
            print('No')
        else:
            for i in range(n):
                if not graph[i]:
                    now = i
            size_c, can = dfs(now, 'c', ind[now])
            if not can and ind[now] != size_b + size_c - 1:
                print('No')
            else:
                if size_a + size_b + size_c == n:
                    print('Yes')
                    print(''.join(graph))
                else:
                    print('No')
