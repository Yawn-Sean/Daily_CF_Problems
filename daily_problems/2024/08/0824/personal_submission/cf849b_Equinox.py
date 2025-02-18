import sys
import math
import heapq

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

sys.stdin = open('in.txt', 'r')

def solve():
    n = II()

    p = LMI()


    for st in [(0, 1), (0, 2), (1, 2)]:
        a, b = st

        vis = [False] * n

        for i in range(n):
            if (a - b) * (p[b] - p[i]) == (p[a] - p[b]) * (b - i):
                vis[i] = True

        res = [x for x in range(n) if not vis[x]]

        if len(res) == 0:
            print('NO')
            return

        ok = True

        for i in range(1, len(res) - 1):
            if (res[i] - res[i - 1]) * (p[res[i + 1]] - p[res[i]]) != (p[res[i]] - p[res[i - 1]]) * (res[i + 1] - res[i]):
                ok = False
                break

        for i in range(len(res) - 1):
            if ((res[i + 1] - res[i]) * (p[b] - p[a]) != (p[res[i + 1]] - p[res[i]]) * (b - a)):
                ok = False
                break

        if ok:
            print('YES')
            return

    print('NO')
    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()