import sys

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

N = 101
def solve():
    n, q, c = MII()
    g = [[0] * (N * N) for _ in range(c + 1)]

    def get(i: int, j: int) -> int:
        return i * 101 + j

    for i in range(n):
        x, y, s = MII()
        for j in range(c + 1):
            g[j][get(x, y)] += (s + j) % (c + 1)

    for k in range(c + 1):
        for i in range(100):
            for j in range(100):
                g[k][get(i + 1, j + 1)] += g[k][get(i + 1, j)] + g[k][get(i, j + 1)] - g[k][get(i, j)]

    ans = []
    for _ in range(q):
        t, x1, y1, x2, y2 = MII()
        t %= c + 1
        ans.append(g[t][get(x2, y2)] - g[t][get(x2, y1 - 1)] - g[t][get(x1 - 1, y2)] + g[t][get(x1 - 1, y1 - 1)])

    print('\n'.join(map(str, ans)))
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()