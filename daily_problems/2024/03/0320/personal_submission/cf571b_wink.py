n, k = map(int, input().split())

v = list(map(int, input().split()))
v.sort()
v = [0] + v


# k 个子数组，b 个子数组长度为 a+1，k - b 个子数组为 a
a, b = divmod(n, k)

# 前 k 个子数组，选了 j 个长度为 a+1 的子数组
f = [[10 ** 18] * (b + 1) for _ in range(k + 1)]

f[0][0] = 0
for i in range(1, k + 1):
    for j in range(min(i + 1, b + 1)):
        # 不合法情况
        if i - j > k - b:
            continue
        # 最后选的长度为只能 a
        if j == 0:
            f[i][j] = f[i - 1][j] + v[i * a] - v[(i - 1) * a + 1]
        # 最后选的长度可以为 a 或者 a+1
        else:
            f[i][j] = min(f[i - 1][j] + v[i * a + j] - v[i * a + j - a + 1],
                          f[i - 1][j - 1] + v[i * a + j] - v[i * a + j - (a + 1) + 1])

print(f[k][b])
