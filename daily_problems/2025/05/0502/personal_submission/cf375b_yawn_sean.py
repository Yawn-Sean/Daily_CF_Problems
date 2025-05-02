# Submission link: https://codeforces.com/problemset/submission/375/318051088#
def main():
    n, m = MII()
    grid = [[int(c) for c in I()] for _ in range(n)]

    cur = [0] * n
    cnt = [0] * (m + 1)

    ans = 0

    for j in range(m):
        for i in range(n):
            cur[i] = cur[i] + 1 if grid[i][j] else 0
        
        for x in cur:
            cnt[x] += 1

        c = 0
        for i in range(m, -1, -1):
            c += cnt[i]
            ans = fmax(ans, c * i)

        for x in cur:
            cnt[x] -= 1

    print(ans)