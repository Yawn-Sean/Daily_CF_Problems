def main():
    n, l, t = MII()
    a = LII()
    # 将时间乘以2
    t *= 2
    d = t % l
    k = t // l

    ans = n * (n - 1) * k

    # 扩展数组以处理环状情况
    a.extend([x + l for x in a])
    left = 0

    for right in range(n):
        while left < 2 * n and a[left] <= a[right] + d:
            left += 1
        ans += (left - right - 1)

    print(ans / 4)
