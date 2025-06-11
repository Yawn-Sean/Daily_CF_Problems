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

# sys.stdin = open('in.txt', 'r')

def solve():
    y1, y2, yw, xb, yb, r = MII()

    sy1, sy2 = 2 * yw - y2 - 2 * r, 2 * yw - y1 - 2 * r

    if (sy2 - sy1 - r) ** 2 * xb ** 2 < r * r * ((yb - sy2 + r) ** 2 + xb ** 2):
    	print(-1)
    else:
    	print((sy2 - yw) * xb / (sy2 - r - yb))

    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()