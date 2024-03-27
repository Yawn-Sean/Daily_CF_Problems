def solve():
    n, u = MI()
    a = LII()
    i, k = 0, 2
    ans = -1
    # (a[k]-a[j]) / (a[k]-a[i])
    # k越大越好, 枚举i, 更新答案
    while i < n and k < n:
        while k+1 < n and a[k+1] - a[i] <= u:
            k += 1
        if i < k-1 and a[k] - a[i] <= u:
            ans = max(ans, (a[k] - a[i+1]) / (a[k] - a[i]))
        i += 1
    print(ans)


def main():
    t = 1
    for _ in range(t):
        solve()

main()
