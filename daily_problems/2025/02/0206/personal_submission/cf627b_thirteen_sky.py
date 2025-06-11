def solve():
    n, k, a, b, q = map(int, input().split())
    orders = [0] * n

    for _ in range(q):
        query = list(map(int, input().split()))

        if query[0] == 1:
            d, ai = query[1], query[2]
            orders[d - 1] += ai
        else:
            p = query[1]
            total_filled = 0

            # 维修前
            for i in range(p - 1):
                total_filled += min(orders[i], b)

            # 维修后
            for i in range(p + k - 1, n):
                total_filled += min(orders[i], a)

            print(total_filled)

solve()
