# Submission link: https://codeforces.com/contest/126/submission/294698696
def main():
    n = II()
    grid = [[int(x) for x in I()] for _ in range(n)]

    ans = 0

    r0 = [0] * n
    c0 = [0] * n

    for i in range(n):
        for j in range(n - 1, i, -1):
            if grid[i][j] != r0[i] ^ c0[j]:
                ans += 1
                r0[i] ^= 1
                c0[j] ^= 1

    r1 = [0] * n
    c1 = [0] * n

    for i in range(n - 1, -1, -1):
        for j in range(i):
            if grid[i][j] != r1[i] ^ c1[j]:
                ans += 1
                r1[i] ^= 1
                c1[j] ^= 1

    for i in range(n):
        if grid[i][i] != r0[i] ^ c0[i] ^ r1[i] ^ c1[i]:
            ans += 1

    print(ans)