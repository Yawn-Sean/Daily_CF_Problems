import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    c = [0, 0]
    n = int(input())
    for _ in range(n):
        x, y = map(int, input().split())
        if x > y:
            c[0] += 1
        elif x < y:
            c[1] += 1
    mid = n - c[0] - c[1]
    ans = mid * (mid - 1) // 2 + \
        mid * (n - mid) + \
        c[0] * c[1]
    return str(ans)


print('\n'.join(solve() for _ in range(int(input()))))


"""
就是按 y=x 划分成两半, #上半 * #下半
对于刚好在 y=x 上的, 特殊处理
"""
