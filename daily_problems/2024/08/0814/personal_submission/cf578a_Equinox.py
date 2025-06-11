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
    a, b = MII()

    if a < b:
        print(-1)
    else:
        res = 1_000_000_007
        L = a - b
        k = L // (2 * b)
        if L >= 2 * b:
            res = fmin(res, L / 2 / k)
        R = a + b
        k = R // (2 * b)
        if R >= 2 * b:
            res = fmin(res, R / 2 / k)
        print(res)
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()