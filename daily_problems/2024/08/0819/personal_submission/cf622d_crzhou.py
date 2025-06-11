n = int(input())
ans = [0] * n * 2
for i in range(1, n // 2 + 1):
    ans[i - 1] = i * 2 - 1
    ans[n - i] = i * 2 - 1  # 奇数
    ans[i + n - 1] = i * 2
    ans[2 * n - i - 1] = i * 2       # 偶数

for i in range(2 * n):
    if not ans[i]:
        ans[i] = n
print(*ans)
