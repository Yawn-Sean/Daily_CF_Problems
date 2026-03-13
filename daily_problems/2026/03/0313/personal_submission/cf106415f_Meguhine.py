# -*- coding: UTF-8 -*-
import sys
from collections import defaultdict, deque

input = lambda: sys.stdin.readline().rstrip()


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    e = defaultdict(list)
    deg = defaultdict(int)
    p = deque(a)
    while p:
        u = p.popleft()
        if u.bit_count() == 1:
            deg[u] = 0
        else:
            v = (1 << u.bit_length()) - u
            deg[u] += 1
            e[v].append(u)
            if v not in deg:
                deg[v] = 0
                p.append(v)

    w = {}
    p = deque([u for u, d in deg.items()if d == 0])
    while p:
        u = p.popleft()

        if u.bit_count() == 1:
            print(f"? {u} {u}", flush=True)
            w[u] = int(input().split()[1]) // 2
        else:
            v = (1 << u.bit_length()) - u
            print(f"? {u} {v}", flush=True)
            w[u] = int(input().split()[1]) - w[v]

        for v in e[u]:
            deg[v] -= 1
            if deg[v] == 0:
                p.append(v)

    print(
        "\n".join(
            map(
                lambda x: "! " + str(w[x]), a
            )
        ),
        flush=True
    )
