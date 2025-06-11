'''
https://codeforces.com/problemset/submission/250/295163149
250C
2024/12/6 Y1
1600
Counter, Greedy
'''
# 计算groupby后每一个x移除后可以带来多少收益，收益=减少的stress次数

from itertools import groupby, pairwise
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    return n, k, a

def solve(n: int, k: int, a: list[int]):
    b = [key for key, _ in groupby(a)]
    cn = [0] * (k + 1)

    p = -1
    for x, y in pairwise(b):
        cn[x] += 1 + (y == p)
        p = x
    cn[b[-1]] += 1

    ans = 0
    for x in range(1, k + 1):
        if cn[x] > cn[ans]:
            ans = x
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
