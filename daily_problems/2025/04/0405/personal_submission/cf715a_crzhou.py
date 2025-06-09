n = II()
ans = [0] * n
ans[0] = 2
for i in range(2, n + 1):
    ans[i - 1] = (i + 1) * (i + 1) * i - (i - 1)
print('\n'.join(map(str, ans)))
