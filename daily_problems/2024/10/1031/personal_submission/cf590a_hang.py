def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    def f(l,r):
        nonlocal ans
        ans = max(ans, (r - l - 1) // 2)
        for j in range(l, (l + r) // 2):
            a[j] = a[l]
        for j in range((l + r) // 2, r):
            a[j] = a[r - 1]
    l = 0
    for r in range(1, n):
        if a[r] == a[r - 1]:
            f(l,r)
            l = r
    f(l,n)
    print(ans)
    print(*a)

main()