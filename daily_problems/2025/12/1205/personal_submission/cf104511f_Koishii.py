import sys
import math

input = lambda: sys.stdin.readline().rstrip()

outs = []
def soviet():
    n, m, v = map(int, input().split())
    s = input()
    ops = []
    for _ in range(m):
        a, x, b, y, c, z = map(int, input().split())
        ops.append((a, x - 1, b, y - 1, c, z - 1))

    cost = [-1] * n
    for i in range(n):
        if s[i] == '1':
            cost[i] = 1

    for _ in range(n):
        for a, x, b, y, c, z in ops:
            if cost[x] != -1 and cost[y] != -1:
                if (cost[z] == -1):
                    cost[z] = a * cost[x] + b * cost[y]
                else:
                    cost[z] = min(cost[z], a * cost[x] + b * cost[y])
    outs.append(v / cost[0] if cost[0] != -1 else 0)


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(map(str, outs)))
