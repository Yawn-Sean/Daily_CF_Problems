def solve():
    n = int(input())
    a = input().strip()
    b = input().strip()

    a = " " + a
    b = " " + b
    ans = 0

    for i in range(1, (n + 1) // 2 + 1):
        l = i
        r = n - i + 1
        if l == r:
            if a[l] != b[l]:
                ans += 1
            continue

        if a[l] == a[r]:
            if b[l] != b[r] and (a[l] == b[l] or a[l] == b[r]):
                ans += 1
            elif b[l] != b[r]:
                ans += 2
        else:
            if (a[l] == b[l] and a[r] == b[r]) or (a[l] == b[r] and a[r] == b[l]):
                continue
            if a[l] == b[l] or a[l] == b[r] or a[r] == b[l] or a[r] == b[r]:
                ans += 1
            elif b[l] == b[r]:
                ans += 1
            else:
                ans += 2

    print(ans)


if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
