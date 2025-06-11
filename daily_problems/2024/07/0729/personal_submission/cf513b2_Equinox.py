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
    n, m = MII()
    p = [0] * n
    m -= 1
    l, r = 0, n - 1
    for i in range(n - 2, -1, -1):
        if m >> i & 1:
            p[r] = n - i - 1
            r -= 1
        else:
            p[l] = n - i - 1
            l += 1
        pass
    p[l] = n
    print(' '.join(map(str, p)))
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()