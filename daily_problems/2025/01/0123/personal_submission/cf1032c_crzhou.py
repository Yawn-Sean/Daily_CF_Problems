n = II()
nums = LII()

f = [[0] * 5 for _ in range(n)]

for i in range(5):
    f[0][i] = 1

for i in range(1, n):
    if nums[i] > nums[i - 1]:
        for j in range(4):
            if f[i - 1][j]:
                for k in range(j + 1, 5):
                    f[i][k] = 1
                break
    elif nums[i] < nums[i - 1]:
        for j in range(4, 0, -1):
            if f[i - 1][j]:
                for k in range(j - 1, -1, -1):
                    f[i][k] = 1
                break
    else:
        for k in range(5):
            flg = False
            for j in range(5):
                if j != k and f[i - 1][j]:
                    flg = True
                    break
            if flg:
                f[i][k] = 1

    flg = False
    for j in range(5):
        if f[i][j]:
            flg = True
            break
    if not flg:
        
        exit(print(-1))

ans = []
for j in range(5):
    if f[-1][j]:
        ans.append(j + 1)
        break

for i in range(n - 2, -1, -1):
    pre = ans[-1] - 1
    if nums[i] < nums[i + 1]:
        for j in range(pre):
            if f[i][j]:
                ans.append(j + 1)
                break
    elif nums[i] > nums[i + 1]:
        for j in range(pre + 1, 5):
            if f[i][j]:
                ans.append(j + 1)
                break
    else:
        for j in range(5):
            if j != pre and f[i][j]:
                ans.append(j + 1)
                break

ans = ans[::-1]
print(' '.join(map(str, ans)))
