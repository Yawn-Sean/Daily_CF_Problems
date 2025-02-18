# Submission link: https://codeforces.com/contest/980/submission/297584526
def main():
    n, k = MII()

    print('YES')

    ans = [['.'] * n for _ in range(4)]
    if k % 2 == 0:
        for i in range(k // 2):
            ans[1][i + 1] = '#'
            ans[2][i + 1] = '#'
    else:
        v = k // 2
        ans[1][n // 2] = '#'
        
        for i in range(1, 3):
            for j in range(1, n // 2):
                if v:
                    v -= 1
                    ans[i][j] = '#'
                    ans[i][n - j - 1] = '#'

    print('\n'.join(''.join(x) for x in ans))