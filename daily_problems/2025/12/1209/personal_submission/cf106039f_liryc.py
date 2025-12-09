'''
2025/12/09 Y2
1800
'''
# dijkstra
from itertools import permutations
from sys import stdin
from collections import Counter, defaultdict
input = lambda: stdin.readline().strip()

def init():
    n, m, k = map(int, input().split())
    edges = Counter()
    for i in range(m):
        u, v, c = map(int, input().split())
        u, v = u - 1, v - 1
        edges[u << 18 | v] = edges[v << 18 | u] = c
    ta = defaultdict(list)
    for u in range(n):
        t = int(input())
        for _ in range(t):
            x, c = map(int, input().split())
            ta[x].append([u, c])
    for a in ta.values():
        for (u, c), (v, _) in permutations(a, 2):
            key = u << 18 | v
            if key in edges:
                if c < edges[key]:
                    edges[key] = c
            else:
                edges[key] = c

    
    return n, m

def solve(n: int, m: int):
    return n + m

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
