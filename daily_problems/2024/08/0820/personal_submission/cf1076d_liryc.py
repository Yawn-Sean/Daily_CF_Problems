'''
https://codeforces.com/contest/1076/submission/277283943
1076D
2024/8/20 Y1
1800
dijkstra
'''
from heapq import heappop, heappush

INF = 5 * 10 ** 15

def init():
    n, m, k = map(int, input().split())
    edges = []
    for _ in range(m):
        x, y, w = map(int, input().split())
        edges.append((x, y, w))
    return n, m, k, edges

def solve(n, m, k, edges):
    global INF
    k = min(k, n - 1)
    ans = []
    g = [[] for _ in range(n + 1)]
    i = 0
    for x, y, w in edges:
        i += 1
        g[x].append((y, w, i))
        g[y].append((x, w, i))
    dist = [INF] * (n + 1)
    hp = []
    hp.append((0, 1, -1))
    dist[1] = 0
    while hp and len(ans) < k:
        d, s, e = heappop(hp)
        if d > dist[s]:
            continue
        if e > 0:
            ans.append(e)
        for t, w, j in g[s]:
            if d + w < dist[t]:
                dist[t] = d + w
                heappush(hp, (dist[t], t, j))
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    if ans:
        print(' '.join(map(str, ans)))
        #print(*ans)
