import sys

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 10**9 + 7

def solve():
    n = II()

    def foo(n: int) -> list[int]:
        if n <= 3:
            return [1] * (n - 1) + [n]
        return [1] * (n - n // 2) + [x * 2 for x in foo(n // 2)]
    print(' '.join(map(str, foo(n))))


if __name__ == "__main__":
    solve()


