for _ in range(times):
    n, m = il()
    m -= 1
    ans = [0] *n
    l, r = 0, n - 1
    for i in range(1, n):
        if m >> (n - i - 1) & 1 :
            ans[r] = i
            r -= 1
        else:
            ans[l] = i
            l += 1
    ans[l] = n
    pl(ans)
