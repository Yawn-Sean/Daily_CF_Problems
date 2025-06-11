n = II()
nums = []

xs = []
os = []

for i in range(n):
    nums.append(I())
    for j in range(n):
        if nums[i][j] == 'x':
            xs.append((i, j))
        elif nums[i][j] == 'o':
            os.append((i, j))

ans = [['.' for _ in range(2 * n - 1)] for _ in range(2 * n - 1)]
ans[n - 1][n - 1] = 'o'

for xx, xy in xs:
    for i, (ox, oy) in enumerate(os):
        dx, dy = xx - ox, xy - oy
        flg = True
        for j, (nox, noy) in enumerate(os):
            if j != i:
                nox += dx
                noy += dy
                if 0 <= nox < n and 0 <= noy < n and nums[nox][noy] == '.':
                    flg = False
                    break
        if flg:
            ans[n - 1 + dx][n - 1 + dy] = 'x'
            break
    else:
        print("NO")
        exit()

print("YES")    
for i in range(2 * n - 1):
    print(''.join(ans[i]))
