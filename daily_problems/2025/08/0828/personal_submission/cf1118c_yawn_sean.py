# Submission link: https://codeforces.com/contest/1118/submission/335793873
def main():
    n = II()
    nums = LII()
    
    cnt = [0] * 1001
    
    for x in nums:
        cnt[x] += 1
    
    ans = [[0] * n for _ in range(n)]
    
    pt = 0
    for i in range(n // 2):
        for j in range(n // 2):
            while pt < 1001 and cnt[pt] < 4:
                pt += 1
            
            if pt == 1001:
                exit(print('NO'))
            
            cnt[pt] -= 4
            ans[i][j] = pt
            ans[n - 1 - i][j] = pt
            ans[i][n - 1 - j] = pt
            ans[n - 1 - i][n - 1 - j] = pt
    
    if n % 2:
        pt = 0
        for i in range(n // 2):
            while pt < 1001 and cnt[pt] < 2:
                pt += 1
            
            if pt == 1001:
                exit(print('NO'))
            
            cnt[pt] -= 2
            ans[i][n // 2] = pt
            ans[n - 1 - i][n // 2] = pt
        
        for i in range(n // 2):
            while pt < 1001 and cnt[pt] < 2:
                pt += 1
            
            if pt == 1001:
                exit(print('NO'))
            
            cnt[pt] -= 2
            ans[n // 2][i] = pt
            ans[n // 2][n - 1 - i] = pt
        
        for i in range(1001):
            if cnt[i]:
                ans[n // 2][n // 2] = i
    
    print('YES')
    print('\n'.join(' '.join(map(str, x)) for x in ans))