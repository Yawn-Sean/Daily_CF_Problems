n, m = MII()

ans = [[[i, i]] for i in range(1, n + 1)]

for i in range(n + 1, n + m + 1):
    x, y = MII()
    ans[x - 1].append([i, x])
    ans[y - 1].append([i, y])

for a in ans:
    print(len(a))
    print('\n'.join(map(lambda x: ' '.join(map(str, x)), a)))
