def solve():
    I()
    n = II()
    res, cnt = 0, 0
    a = [[0] * n for _ in range(n)]
    for i in range(n):
        c = I()
        for j in range(n):
            if c[j] == '1':
                cnt += 1
                a[i][j] = 1
            else:
                a[i][j] = 0
    for i in range(n):
        cur, j, k = 0, i, 0
        while k < n:
            if a[k][j]:
                cur += 1
            k += 1
            j = (j + 1) % n
        res = max(res, cur)
    print(n + cnt - res * 2)
def main():
    t = II()
    while t:
        solve()
        t -= 1
main()
