# Submission link: https://codeforces.com/contest/873/submission/292694352
def main():
    n, m, k = MII()
    grid = [LII() for _ in range(n)]

    ans = 0
    cnt = 0

    acc = [0] * (n + 1)
    for i in range(m):
        for j in range(n):
            acc[j + 1] = acc[j] + grid[j][i]
        
        res = 0
        chosen_idx = 0
            
        idx = 0
        
        for j in range(n):
            if grid[j][i]:
                v = acc[fmin(j + k, n)] - acc[j]
                if v > res:
                    res = v
                    chosen_idx = idx
                idx += 1
        
        ans += res
        cnt += chosen_idx

    print(ans, cnt)