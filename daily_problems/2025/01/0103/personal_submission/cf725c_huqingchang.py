def main():
    s = I()
    d = defaultdict(list)
    for i, j in enumerate(s):
        d[j].append(i)
    ans = [[''] * 13 for _ in range(2)]
    doubleCh = ''
    for ch in ascii_uppercase:
        if len(d[ch]) == 2:
            doubleCh = ch
            break
    x0, x1 = d[doubleCh]
    d = x1 - x0
    if d & 1:
        if d == 1:
            exit(print('Impossible'))
        half = d >> 1
        for i in range(13 - half, 13):
            ans[0][i] = s[i - (13 - half) + x0 + 1]
        for i in range(12, 12 - half, -1):
            ans[1][i] = s[13 - i + x0 + half]
        ans[0][-half - 1] = doubleCh
        i, j = 0, 11 - half
        for k in range(x1 + 1, 27):
            tar = s[k]
            if j >= 0:
                ans[i][j] = tar
                if i == 0:
                    j -= 1
                else:
                    j += 1
            else:
                i, j = 1, 0
                ans[i][j] = tar
                j = 1
        if j == -1:
            i, j = 1, 0
        for k in range(x0):
            tar = s[k]
            if j >= 0:
                ans[i][j] = tar
                if i == 0:
                    j -= 1
                else:
                    j += 1
            else:
                i, j = 1, 0
                ans[i][j] = tar
                j = 1
        for r in ans:
            print(''.join(r))
    else:
        half = d >> 1
        for i in range(13 - half, 13):
            ans[0][i] = s[i - (13 - half) + x0]
        for i in range(12, 12 - half, -1):
            ans[1][i] = s[12 - i + x0 + half]
        i, j = 0, 12 - half
        for k in range(x1 + 1, 27):
            tar = s[k]
            if j >= 0:
                ans[i][j] = tar
                if i == 0:
                    j -= 1
                else:
                    j += 1
            else:
                i, j = 1, 0
                ans[i][j] = tar
                j = 1
        if j == -1:
            i, j = 1, 0
        for k in range(x0):
            tar = s[k]
            if j >= 0:
                ans[i][j] = tar
                if i == 0:
                    j -= 1
                else:
                    j += 1
            else:
                i, j = 1, 0
                ans[i][j] = tar
                j = 1
        for r in ans:
            print(''.join(r))


T = 1
for ii in range(T):
    # print(main())
    main()
