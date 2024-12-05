# Submission link: https://codeforces.com/contest/228/submission/294872940
def main():
    n, m = MII()
    grid = [[1 if c == '*' else 0 for c in I()] for _ in range(n)]

    ans = [[-1] * m for _ in range(n)]
    nans = [[-1] * m for _ in range(n)]

    for i in range(n - 1):
        for j in range(m - 1):
            ans[i][j] = 0
            for di in range(2):
                for dj in range(2):
                    ans[i][j] = ans[i][j] * 2 + grid[i + di][j + dj]

    res = 0
    for k in range(1, 8):
        sz = 1 << k
        
        for i in range(n - sz * 2 + 1):
            for j in range(m - sz * 2 + 1):
                msk = 0
                for di in range(2):
                    for dj in range(2):
                        msk *= 2
                        if ans[i + di * sz][j + dj * sz] == 15:
                            msk += 1
                
                flg = True
                for di in range(2):
                    for dj in range(2):
                        if ans[i + di * sz][j + dj * sz] != 15 and ans[i + di * sz][j + dj * sz] != msk:
                            flg = False

                if flg:
                    nans[i][j] = msk
        
        for i in range(n):
            for j in range(m):
                ans[i][j] = nans[i][j]
                nans[i][j] = -1
                
                if ans[i][j] != -1:
                    res += 1

    print(res)