import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n = int(input())
    a = list(map(int, input().split()))
    m = min(n, a[0])
    b = [0] * m
    j = 0
    for i in range(m - 1, -1, -1):
        while j < n and a[j] >= i + 1:
            j += 1
        b[i] = min(a[i], j)
    return str(sum(a) - sum(b))


print('\n'.join(
    solve() for _ in range(int(input()))
))


"""
题目意思就是给定一个数组 a, 保证 a 单调不递增, a[i]>=a[i+1]
然后要删去最少的方格, 使得按 y=x 对称
显然只要取 min 即可
"""
