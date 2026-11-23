# Submission link: https://codeforces.com/gym/104146/submission/399594171
def main(): 
    n = II()
    
    if n == 2 or n == 4:
        print('NO')
    
    else:
        print('YES')
    
        if n == 6:
            print('AABBBB')
            print('CDDEEE')
            print('CDDFFF')
            print('CDDFFF')
            print('CDDFFF')
            print('CDDFFF')
    
        elif n % 2:
            ans = [['E'] * n for _ in range(n)]
            
            for i in range(n // 2):
                for j in range(i + 1):
                    ans[i][j] = 'A' if i % 2 == 0 else 'C'
                for j in range(i + 1, n):
                    ans[i][j] = 'B' if i % 2 == 0 else 'D'
            
            print('\n'.join(''.join(x) for x in ans))
    
        else:
            ans = [['H'] * n for _ in range(n)]
            for i in range(n // 2 - 2):
                for j in range(i + 1):
                    ans[i][j] = 'A' if i % 2 == 0 else 'C'
                for j in range(i + 1, n):
                    ans[i][j] = 'B' if i % 2 == 0 else 'D'
            
            for j in range(n):
                ans[n // 2 - 2][j] = 'E'
            
            for i in range(n // 2 - 1, n):
                ans[i][0] = 'F'
            
            for i in range(n // 2 - 1, n // 2 + 1):
                for j in range(1, n):
                    ans[i][j] = 'G'
            
            print('\n'.join(''.join(x) for x in ans))