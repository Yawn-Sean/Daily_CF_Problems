import sys
from sortedcontainers import SortedList
from bisect import bisect_left
from bisect import bisect_right
from string import ascii_uppercase
from math import inf

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 10**9 + 7

sys.stdin = open('in.txt', 'r')

def solve():
    n, m, h, t = MII()
    adj = [[] for _ in range(n)]
    for _ in range(m):
        a, b = MII()
        a -= 1
        b -= 1
        adj[a].append(b)
        adj[b].append(a)

    vis = [0] * n
    def check(u: int, v: int) -> None:
        if len(adj[u]) <= h or len(adj[v]) <= t:
            return

        cu = cv = 0
        vis[u] = vis[v] = -1
        for x in adj[u]:
            if not vis[x]:
                cu += 1
            vis[x] |= 1

        for x in adj[v]:
            if not vis[x]:
                cv += 1
            vis[x] |= 2

        if cu + cv < h + t:
            for x in adj[u]:
                vis[x] = 0
            for x in adj[v]:
                vis[x] = 0
            vis[u] = vis[v] = 0
            return

        ver_u = [i for i in range(n) if vis[i] == 1][:h]
        ver_v = [i for i in range(n) if vis[i] == 2][:t]
        buf = [i for i in range(n) if vis[i] == 3]

        while len(ver_u) < h:
            ver_u.append(buf.pop())
        while len(ver_v) < t:
            ver_v.append(buf.pop())

        print('YES')
        print(u + 1, v + 1)
        print(' '.join(str(i + 1) for i in ver_u))
        print(' '.join(str(i + 1) for i in ver_v))
        exit()

    for u in range(n):
        for v in adj[u]:
            check(u, v)

    print('NO')

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()