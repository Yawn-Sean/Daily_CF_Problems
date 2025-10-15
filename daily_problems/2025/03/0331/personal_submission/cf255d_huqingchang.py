def main():
    n, x, y, c = MII()
    if c == 1:
        return 0
    low, high = 1, n ** 2
    ans = high

    def get_waste(z):
        return z ** 2 if z >= 0 else 0

    def f(t):
        if t > 0:
            return t * (t + 1) // 2
        return 0

    def check(t):
        tot = 2 * t ** 2 + 2 * t + 1
        tot -= get_waste(t - x + 1) + get_waste(t - y + 1) + get_waste(t - (n - x)) + get_waste(t - (n - y))
        tot += f(t - n + y - x) + f(t - n + x - y) + f(t - x - y + 1) + f(t + y + x - 2 * n - 1)
        return tot >= c

    while low <= high:
        mid = (low + high) // 2
        if check(mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans


T = 1
for ii in range(T):
    print(main())
