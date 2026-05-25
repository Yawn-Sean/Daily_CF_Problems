import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n, A = map(int, input().split())
    A *= 2
    if n - 2 > A:
        return "No"
    if n == 3:
        return f"Yes\n0 0\n1 0\n1 {A}"
    A -= (n - 2)
    xs = [i // 2 for i in range(n)]
    ys = [-(i & 1) for i in range(n)]
    ys[-1] = 1
    ys[1] -= A
    return "Yes\n" + '\n'.join(f"{x} {y}" for x, y in zip(xs, ys))


total_cases = int(input())
print('\n'.join(
    solve() for _ in range(total_cases)
))


"""
n   minA
3   1/2
4   1
5   3/2
6   2

在下面构建一排锯齿型, 最后一个点的 y 坐标设为 1
剩余的面积, 把第一个三角形往下拉长即可
"""
