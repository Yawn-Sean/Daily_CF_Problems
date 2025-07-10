"""
直接两两枚举火烈鸟，预处理出所有直线方程
然后枚举直线方程，看方程的零点
假设某个直线方程出现了 cnt 次，直线上有 c 个点，则有 c * (c - 1) // 2 = cnt
=> c * (c - 1) = 2 * cnt，可以直接对 2 * cnt 进行开方，得到整数 + 1 就是 c
"""
import math
from collections import defaultdict

n, m = map(int, input().split())
positions = []
for i in range(m):
    p = tuple(map(int, input().split()))
    positions.append(p)

cnt = defaultdict(int)
for i in range(m):
    for j in range(i):
        x1, y1 = positions[i][0], positions[i][1]
        x2, y2 = positions[j][0], positions[j][1]
        A = y1 - y2
        B = x2 - x1
        C = x1 * y2 - x2 * y1
        g = math.gcd(A, B, C)
        if g < 0:
            g *= -1
        assert g != 0
        A //= g
        B //= g
        C //= g
        if A < 0:
            A *= -1
            B *= -1
            C *= -1
        elif A == 0 and B < 0:
            B *= -1
            C *= -1
        elif A == 0 and B == 0 and C < 0:
            C *= -1
        cnt[(A, B, C)] += 1

res = [0 for i in range(n + 1)]
for key, val in cnt.items():
    A, B, C = key[0], key[1], key[2]
    if A != 0 and C % A == 0:
        i = -C // A
        if i > 0 and i <= n:
            res[i] = max(res[i], val)
s = 0
for i in range(1, n + 1):
    s += math.isqrt(res[i] * 2) + 1
print(s)
