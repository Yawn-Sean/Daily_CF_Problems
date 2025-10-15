"""
对于所有的 k, l <= k <= r，求 sum(g(k))
4 <= k <= 1e18
g(k) = z，f(k)^z <= k
f(k) = t, 2^t <= k，所以 2 <= t <= 64
所以 f(k)^z = t^z <= 1e18，z <= 64
对于连续的 k，f(k) 是固定的，一共也只有 63 种不同的 f(k)
先根据 f(k) 的不同，对 k 进行分段
对于 f(k) 相同的段，再按照 g(k) 分段，也就是说每段再分 63 段
也就是说每次询问分成 3600 段左右，每段 O(1) 求和，一共 1e5 次询问
"""
import sys

input = lambda: sys.stdin.readline().strip()
T = int(input())

mod = int(1e9 + 7)
while T > 0:
    T -= 1

    l, r = map(int, input().split())
    res = 0
    st = 0
    while (1 << (st + 1)) <= l:
        st += 1

    left, right = l, l
    while (1 << st) <= r:
        right = (1 << (st + 1)) - 1
        right = min(right, r)

        # st 就是 f(k)
        z = 0
        prod = 1
        while prod * st <= left:
            prod *= st
            z += 1

        left2, right2 = left, left
        while prod <= right:
            right2 = prod * st - 1
            right2 = min(right2, right)
            cnt = right2 - left2 + 1
            res += cnt * z
            z += 1
            prod *= st
            left2 = right2 + 1

        left = right + 1
        st += 1

    print(res % mod)
