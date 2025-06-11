n, k = MII()
a = LII()

def check(mx: int) -> int:
    f = [1] * (n + 1)
    for i in range(1, n):
        for j in range(i):
            if abs(a[i] - a[j]) <= mx * (i - j):    # 阶梯
                f[i + 1] = max(f[i + 1], f[j + 1] + 1)
    return max(f)

print(bisect_left(range(0, max(a) - min(a)), n - k, key=check))
