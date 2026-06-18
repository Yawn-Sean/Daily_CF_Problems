import sys
from array import array
from math import gcd

input = lambda: sys.stdin.readline().rstrip()


n, K = map(int, input().split())
a = list(map(int, input().split()))

N = max(a) + 1
ans = array('i', [1] * K)
cnt = array('i', [0] * N)
for x in a:
    cnt[x] -= 1
for _ in range(1, n):
    u, v = map(lambda s: int(s) - 1, input().split())
    au, av = a[u], a[v]
    cnt[au] += 1
    cnt[av] += 1
    cnt[gcd(au, av)] -= 1
for x in range(1, K + 1):
    for y in range(x, N, x):
        ans[x - 1] += cnt[y]
print(' '.join(map(str, ans)))


"""
森林中树的个数是多少呢 ?
! 点数 - 边数
所以我们只要统计, 对于每个 i, 删去了多少点, 删去了多少边
点数 = N - 删去的点数
边数 = N-1 - 删去的边数
答案 = 1 - 删去的点数 + 删去的边数
这些可以用(度数+容斥)来统计, 就做完啦

当 i 是 au 的因子时, 删了一个点, ans[i] -= 1
当 i 是 au 的因子时, 删了 degu 条边, ans[i] += degu
当 i 是 gcd(au,av) 的因子时, 多删了一条边, ans[i] -= 1
"""
