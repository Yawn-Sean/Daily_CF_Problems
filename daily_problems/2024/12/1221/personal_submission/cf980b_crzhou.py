n, k = MII()

print("YES")
ans = [['.'] * n for _ in range(4)]

if k == 1:
    ans[1][n // 2] = '#'
elif k == 3:
    ans[1][n // 2 - 1] = ans[1][n // 2] = ans[1][n // 2 + 1] = '#'
else:
    for i in range((k + 1) // 2):
        ans[1][i + 1] = ans[2][i + 1] = '#'
    if k % 2:
        ans[1][2] = '.'
        
print('\n'.join(map(''.join, ans)))
