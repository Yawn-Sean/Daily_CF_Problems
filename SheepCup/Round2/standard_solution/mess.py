def main():
    mod = 10 ** 9 + 7

    n, q = MII()
    nums = LII()

    acc1 = [0] * (n + 1)
    acc2 = [0] * (n + 1)

    for i in range(n):
        acc1[i + 1] = acc1[i] + nums[i]
        acc2[i + 1] = acc2[i] + nums[i] * (nums[i] - 1) // 2

    f = [1] * (10 ** 5 + 2)

    for i in range(1, 10 ** 5 + 2):
        f[i] = f[i - 1] * i % mod

    outs = []

    for _ in range(q):
        l, r = MII()
        pl = bisect.bisect_left(acc1, l)
        pr = bisect.bisect_right(acc1, r) - 1
        
        if pl > pr: outs.append(0)
        else:
            ans = (r - l) * (r - l + 1) // 2 - (acc2[pr] - acc2[pl] + (acc1[pl] - l) * (acc1[pl] - l + 1) // 2 + (r - acc1[pr]) * (r - acc1[pr] - 1) // 2)
            outs.append(ans % mod * (mod + 1) // 2 % mod * f[r - l + 1] % mod)
    print('\n'.join(map(str, outs)))