# Submission link: https://codeforces.com/gym/104017/submission/387668199
def main():
    n = II()
    
    pos = [0] * (n * n + 1)
    
    for i in range(n):
        nums = LII()
        for j in range(n):
            pos[nums[j]] = (i, j)
    
    ans = 0
    
    c_row = [0] * n
    c_col = [0] * n
    
    for i in range(1, n * n + 1):
        x, y = pos[i]
        
        ans += c_row[x] * (n - 1 - c_col[y])
        ans += c_col[y] * (n - 1 - c_row[x])
        
        c_row[x] += 1
        c_col[y] += 1
    
    print(ans // 2)