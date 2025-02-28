k = II()
if k == 0:
    print('+')
else:
    ans = [[1, 1], [1, 0]]

    for _ in range(k - 1):
        n = len(ans)
        new_ans = []
        for i in range(n):
            new_ans.append(ans[i] + ans[i])
        for i in range(n):
            new_ans.append(new_ans[i].copy())
        for i in range(n):
            for j in range(n):
                new_ans[i + n][j + n] ^= 1
        ans = new_ans

    for i in range(1 << k):
        for j in range(1 << k):
            if ans[i][j]:
                ans[i][j] = '+'
            else:
                ans[i][j] = '*'

    print('\n'.join(''.join(ans[i]) for i in range(1 << k)))
