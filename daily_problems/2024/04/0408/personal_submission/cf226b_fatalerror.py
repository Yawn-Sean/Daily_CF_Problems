import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from itertools import accumulate

n = ii()
arr = lii()
arr.sort(reverse=True)
pres = list(accumulate(arr, initial=0))

memo = [-1] * (10**5+1)
def calc(k):
    if memo[k] != -1:
        return memo[k]
    if k == 1:
        res = sum(x*d for d, x in enumerate(arr))
    else:
        # 完全k叉树，值越大节点深度越小
        res = 0
        p = 1
        s = 0
        d = 0
        while s < n:
            s2 = min(s + p, n)
            res += (pres[s2] - pres[s]) * d
            p *= k
            s = s2
            d += 1
    memo[k] = res
    return res

nq = ii()
queries = lii()
print(*(calc(k) for k in queries))