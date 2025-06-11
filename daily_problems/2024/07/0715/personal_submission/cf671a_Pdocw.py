def main():
    """
    1. 从 Adil 开始的起点出发，去拿瓶子再丢掉。
    2. 从 Bera 开始的起点出发，去拿瓶子再丢掉。
    3. 从垃圾桶出发，去拿瓶子再丢掉。
    """
    ax, ay, bx, by, tx, ty = MII()

    def fa(x, y):
        return ((x - ax) * (x - ax) + (y - ay) * (y - ay)) ** 0.5

    def fb(x, y):
        return ((x - bx) * (x - bx) + (y - by) * (y - by)) ** 0.5

    def ft(x, y):
        return ((x - tx) * (x - tx) + (y - ty) * (y - ty)) ** 0.5

    tot = 0
    dp1 = dp2 = dp3 = -4e9
    n = II()

    for _ in range(n):
        x, y = MII()
        tot += 2 * ft(x, y)
        # dp1: 从 Adil 开始的起点出发，去拿瓶子再丢掉。
        # dp2: 从 Bera 开始的起点出发，去拿瓶子再丢掉。
        # dp3: 在 dp1和dp2的基础上，从 Bera 或 Adil 的起点出发，去拿瓶子再丢掉。
        dp1, dp2, dp3 = (
            max(dp1, ft(x, y) - fa(x, y)),
            max(dp2, ft(x, y) - fb(x, y)),
            max(dp3, dp1 + ft(x, y) - fb(x, y), dp2 + ft(x, y) - fa(x, y)),
        )

    print(tot - max(dp1, dp2, dp3))
    return
