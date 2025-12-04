import sys
import math

outs = []
def soviet():
    r, n, l = map(int, input().split())
    ans = math.pi * r * r
    ans += l * r * n
    ans += l * l / 2 / math.tan(math.pi / n) * n / 2
    outs.append(ans)


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(map(str, outs)))
