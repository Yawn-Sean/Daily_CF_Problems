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

def solve():
    n, k, x = MII()
    a = LMI()

    x = pow(x, k)

    pre, suf = [0] * n, [0] * n

    pre[0], suf[n - 1] = a[0], a[n - 1]

    for i in range(1, n):
        pre[i] = pre[i - 1] | a[i]
    for i in range(n - 2, -1, -1):
        suf[i] = suf[i + 1] | a[i]

    res = 0

    for i, v in enumerate(a):
        t = x * v
        if i:
            t |= pre[i - 1]
        if i + 1 < n:
            t |= suf[i + 1]
        res = fmax(res, t)

    print(res)
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()