# Submission link: https://codeforces.com/gym/105198/submission/360139149
def main(): 
    n = II()
    
    if n == 3:
        print(1, 1, 2)
        print(1, 4, 3)
        print(2, 3, 3)
    else:
        ans = [[1] * n for _ in range(n)]
        
        if n > 2:
            v = 1024 - n
            if n % 2 == 0:
                ans[0][0] += v
                for i in range(1, n - 1):
                    ans[i][i + 1] += v
                ans[n - 1][1] += v
            else:
                ans[0][0] += v
                ans[1][n - 2] += v
                for i in range(2, n - 2):
                    ans[i][i - 1] += v
                ans[n - 2][n - 1] += v
                ans[n - 1][n - 3] += v
        
        print('\n'.join(' '.join(map(str, x)) for x in ans))