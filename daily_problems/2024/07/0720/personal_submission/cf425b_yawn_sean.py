# Submission Link: https://codeforces.com/contest/425/submission/271452452
def main():
    n, m, k = MII()

    grid = [LII() for _ in range(n)]

    ans = k + 1
    if m <= k:
        for msk in range(1 << m - 1):
            cur = [0] * m
            for i in range(m):
                if msk >> i & 1:
                    cur[i] = 1
            
            res = 0
            for i in range(n):
                cnt = 0
                for j in range(m):
                    if cur[j] == grid[i][j]:
                        cnt += 1
                res += min(cnt, m - cnt)
            if res < ans:
                ans = res
    else:
        for i in range(m):
            res = 0
            for j in range(m):
                cnt = 0
                for x in range(n):
                    if grid[x][j] == grid[x][i]:
                        cnt += 1
                res += min(cnt, n - cnt)
            if res < ans:
                ans = res

    print(ans if ans <= k else -1)