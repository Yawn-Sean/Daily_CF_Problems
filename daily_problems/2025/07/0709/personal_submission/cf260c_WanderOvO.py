"""
假设最开始选的 i，则重新放完之后，理论上 i 位置的球的个数应该是全场并列最少的
因为总是需要先把其他的给放了，才能填一次 i 位置
假设操作完之后最小值是 val，则说明放了 val 轮完整的
考虑所有等于 val 的位置，假设某个为 p，考虑 p + 1 和 x 之间的那些位置
假设这些位置的值都 > val，则说明 p 位置是可行的
特别地，p = x 时是一定可行的
"""
import math

n, x = map(int, input().split())
x -= 1
a = list(map(int, input().split()))
min_val = min(a)
pos = [i for i, val in enumerate(a) if val == min_val]

st = [[0 for _ in range(n)] for _ in range(18)]
for i in range(n):
    st[0][i] = a[i]
for j in range(1, 18):
    for i in range(n):
        if i + (1 << j) - 1 >= n:
            break
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))])

def query(l: int, r: int) -> int:
    k = int(math.log2(r - l + 1))
    return min(st[k][l], st[k][r - (1 << k) + 1])

for p in pos:
    if p < x:
        if query(p + 1, x) > min_val:
            for i in range(p + 1, x + 1):
                a[i] -= 1
            for i in range(n):
                a[i] -= min_val
            a[p] = min_val * n + x - p
            break
    elif p > x:
        mn = query(0, x)
        if p + 1 < n:
            mn = min(mn, query(p + 1, n - 1))
        if mn > min_val:
            for i in range(x + 1):
                a[i] -= 1
            for i in range(p + 1, n):
                a[i] -= 1
            for i in range(n):
                a[i] -= min_val
            a[p] = min_val * n + n - 1 - p + x + 1
            break
    else:
        for i in range(n):
            a[i] -= min_val
        a[p] = min_val * n
        break

for val in a:
    print(val, end=' ')
