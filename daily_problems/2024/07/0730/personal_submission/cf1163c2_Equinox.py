import sys
from math import gcd
from collections import Counter

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 1_000_000_007

sys.stdin = open('in.txt', 'r')

def solve():
    n = II()
    X, Y = [], []
    for _ in range(n):
        x, y = MII()
        X.append(x)
        Y.append(y)

    st = set()

    for i in range(n):
        for j in range(i):
            dx, dy = X[i] - X[j], Y[i] - Y[j]
            g = gcd(dx, dy)
            dx /= g
            dy /= g
            if dx < 0 or (dx == 0 and dy < 0):
                dx = -dx
                dy = -dy
            st.add((dx, dy, X[i] * dy - Y[i] * dx))

    m = len(st)
    res = m * (m - 1) // 2

    cnt = Counter()

    for dx, dy, k in st:
        res -= cnt[(dx, dy)]
        cnt[(dx, dy)] += 1

    print(res)

    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()