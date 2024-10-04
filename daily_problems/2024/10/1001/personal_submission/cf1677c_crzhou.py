t = II()
for _ in range(t):
    n = II()
    a = LII()
    b = LII()

    pos = [0] * (n + 1)
    vis = [False] * (n + 1)
    sum_pairs = 0

    for j in range(n):
        pos[a[j]] = j + 1

    for j in range(1, n + 1):
        if not vis[j]:
            size = 0
            k = j
            while not vis[k]:
                vis[k] = True
                size += 1
                k = b[pos[k] - 1]
            sum_pairs += size // 2

    print(2 * sum_pairs * (n - sum_pairs))
