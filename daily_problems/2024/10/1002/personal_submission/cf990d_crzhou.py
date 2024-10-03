n, a, b = MII()

if a > 1 and b > 1 or a == b == 1 and 2 <= n <= 3:
    print("NO")
else:
    print("YES")
    tmp = fmax(a, b)
    ans = [[0] * n for _ in range(n)]
    for i in range(tmp, n):
        ans[i][(i + 1) % n] = 1
        ans[(i + 1) % n][i] = 1

    if a == 1:
        for i in range(n):
            for j in range(n):
                if i != j:
                    ans[i][j] ^= 1

    print("\n".join("".join(map(str, row)) for row in ans))
