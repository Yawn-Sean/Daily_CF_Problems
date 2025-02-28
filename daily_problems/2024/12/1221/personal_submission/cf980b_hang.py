def main():
    n,k = map(int, input().split())
    print('YES')
    ans = [['.'] * n for _ in range(4)]
    if k % 2 == 0:
        for i in range(k // 2):
            ans[1][i + 1] = '#'
            ans[2][i + 1] = '#'
    else:
        t = k // 2
        ans[1][n // 2] = '#'
        for i in range(1,3):
            for j in range(1, n // 2):
                if t:
                    t -= 1
                    ans[i][j] = '#'
                    ans[i][n - j - 1] = '#'
    for i in range(4):
        print(''.join(ans[i]))

main()