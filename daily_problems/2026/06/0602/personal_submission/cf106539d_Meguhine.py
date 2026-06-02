import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n, m = map(int, input().split())
    p = m // 2 + 1
    return str(min(n, p))


print('\n'.join(
    solve() for _ in range(int(input()))
))


"""
猜一发是杨辉三角
似乎真的是诶!
相当于长为 n 的对错序列, 如果里面有 x 个错
那么第 x+1 个人就会胜利
所以就是杨辉三角
"""
