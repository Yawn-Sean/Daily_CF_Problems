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
    n, x = MII()
    l = r = x
    res = 0
    for i in range(n):
        L, R = MII()
        if L > r or R < l:
            nl, nr = min(r, R), max(l, L)
            res += nr - nl
            l, r = nl, nr
        else:
            nl, nr = max(l, L), min(r, R)
            l, r = nl, nr
    print(res)

    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()