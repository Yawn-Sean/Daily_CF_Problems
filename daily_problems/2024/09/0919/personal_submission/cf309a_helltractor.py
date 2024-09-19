# 考虑每种排列的碰撞次数
# t >= l时，两个方向均考虑： cnt1 = sum(i * c(n - 1, i) for i in range(n)) * 2 = (n - 1) * pow(2, n - 2) * 2 = (n - 1) * pow(2, n - 1)
# t < l时，只考虑一个方向： tmp = r - i - 1, cnt2 = tmp * pow(2, tmp - 1) * pow(2, n - tmp - 1)
# ans = sum(cnt2 + div * cnt1 for i in range(n)) -> ans / pow(2, n)
# 化简得 ans = n * (n - 1) * div * 2 / 4 + sum(tmp for i in range(n)) / 4
def CF309A():
    n, l, t = MII()
    a = LII()
    div, t = divmod(t, l)
    ans = div * (n - 1) * n * 2
    b = a + [l + x for x in a]
    for i, x in enumerate(a):
        r = bisect_right(b, x + 2 * t)
        tmp = r - i - 1
        ans += tmp
    print(ans / 4)
