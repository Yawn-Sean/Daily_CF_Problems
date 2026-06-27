import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for l in (0, 1):
        for r in (n - 2, n - 1):
            if l <= r:
                ans ^= sum(a[l:r + 1])
    return str(ans)


print('\n'.join(solve() for _ in range(int(input()))))


"""
最终求的是异或和的异或和
对于一个线段 [l,r] (0-index-based)
左边有 max(0, l-1) 个分割点
右边有 max(0, n-r-2) 个分割点
如果分割点个数 >0, 那么就有 2^c 种包括这个线段的方法
那么这个线段的总贡献就是 0
所以枚举 l=0,1; r=(n-2), (n-1) 即可
"""
