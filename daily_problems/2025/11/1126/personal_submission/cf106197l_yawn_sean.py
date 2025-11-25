# Submission link: https://codeforces.com/gym/106197/submission/350585012
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        
        ans = [[1] * n for _ in range(n)]
        
        for i in range(n):
            for j in range(i):
                ans[i][j] += 2
        
        for i in range(n // 2):
            ans[n - i - 1][i * 2] += 1
            ans[n - i - 1][i * 2 + 1] += 1
        
        if n % 2: ans[n - 1][n - 1] += 1
    
        for x in ans:
            outs.append(''.join(map(str, x)))
    
    print('\n'.join(outs))