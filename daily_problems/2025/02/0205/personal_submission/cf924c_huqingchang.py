def main():
    n = II()
    res = LII()
    left = [1] * n
    for i in range(1, n):
        left[i] = max(left[i - 1], res[i] + 1)
    for i in range(n - 2, -1, -1):
        left[i] = max(left[i], left[i + 1] - 1)
    ans = 0
    for i in range(n):
        ans += left[i] - 1 - res[i]
    return ans


T = 1
for ii in range(T):
    print(main())
