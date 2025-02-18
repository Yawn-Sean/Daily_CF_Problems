def main():
    n, k, x = MII()
    nums = LII()

    v = pow(x, k)

    pref = nums[:]
    suff = nums[:]
    for i in range(1, n):
        pref[i] |= pref[i-1]

    for i in range(n - 1, 0, -1):
        suff[i-1] |= suff[i]

    ans = 0
    for i in range(n):
        cur = nums[i] * v
        if i: cur |= pref[i-1]
        if i + 1 < n: cur |= suff[i+1]
        ans = max(ans, cur)

    print(ans)
    return
