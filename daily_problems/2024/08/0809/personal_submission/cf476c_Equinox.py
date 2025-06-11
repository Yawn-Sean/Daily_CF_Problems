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
    print((a + a * (1 + a) // 2 * b) * b * (b - 1) // 2 % P)
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()