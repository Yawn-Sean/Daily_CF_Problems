"""
结果只与起点和终点坐标和奇偶性是否相同有关。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    sx, sy = lii()
    target = (sx+sy) % 2
    indices = [set(), set()]
    for i in range(1, n+1):
        x, y = lii()
        indices[(x+y)%2].add(i)

    def choose_by_self(i):
        nonlocal n
        if indices[i]:
            print(indices[i].pop(), flush=True)
        else:
            print(indices[i^1].pop(), flush=True)
        n -= 1

    def choose_by_opponent():
        nonlocal n
        i = ii()
        if i in indices[0]:
            indices[0].remove(i)
        else:
            indices[1].remove(i)
        n -= 1

    if len(indices[target]) >= len(indices[target^1]):
        print('First', flush=True)
    else:
        print('Second', flush=True)
        choose_by_opponent()
        target ^= 1

    while n > 0:
        choose_by_self(target^1)
        if n == 0:
            break
        choose_by_opponent()


for  _ in range(ii()):
    solve()