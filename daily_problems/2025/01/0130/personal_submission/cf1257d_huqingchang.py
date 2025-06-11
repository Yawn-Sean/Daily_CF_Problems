def main():
    n = II()
    A = LII()
    m = II()
    lis = [0] * (n + 1)
    for _ in range(m):
        pi, si = MII()
        lis[si] = max(lis[si], pi)
    tmp = 0
    for i in range(n, 0, -1):
        tmp = max(tmp, lis[i])
        lis[i] = tmp
    if max(A) > lis[1]:
        return -1
    ans = 1
    start = mx = 0
    for r in range(n):
        mx = max(mx, A[r])
        if lis[r - start + 1] < mx:
            ans += 1
            start = r
            mx = A[r]
    return ans


T = II()
for ii in range(T):
    print(main())
