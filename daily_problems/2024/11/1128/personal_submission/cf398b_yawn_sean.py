# Submission link: https://codeforces.com/contest/398/submission/293573106
def main():
    n, m = MII()
    cnt_r = [0] * n
    cnt_c = [0] * n
    
    for _ in range(m):
        x, y = GMI()
        cnt_r[x] = 1
        cnt_c[y] = 1
    
    v1 = n - sum(cnt_r)
    v2 = n - sum(cnt_c)
    
    dp = [[0] * (v2 + 2) for _ in range(v1 + 2)]
    
    for i in range(v1, -1, -1):
        for j in range(v2, -1, -1):
            if i == v1 and j == v2: continue
            dp[i][j] = (n * n + (v1 - i) * (v2 - j) * dp[i + 1][j + 1]
                        + (v1 - i) * (n - v2 + j) * dp[i + 1][j]
                        + (n - v1 + i) * (v2 - j) * dp[i][j + 1]) / (n * n - (n - v1 + i) * (n - v2 + j))
    
    print(dp[0][0])