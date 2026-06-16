import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> int:
    a, b, c, d, e = map(int, input().split())
    return min(a + d, b + e, a + c + e, b + c + d)


print(min(solve() for _ in range(int(input()))))


"""
最大流 = 最小割
min(a+d, b+e, a+c+e, b+c+d)
"""
