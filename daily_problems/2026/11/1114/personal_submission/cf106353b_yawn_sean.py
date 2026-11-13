# Submission link: https://codeforces.com/gym/106353/submission/398407381
def main():
    n = II()
    
    bills    = [1, 2, 5, 10, 20, 50, 100, 500, 200]
    bounds   = [1, 4, 1,  1,  4,  1,   1,  20,  50]
    suff_gcd = [1, 1, 5, 10, 10, 50, 100, 100, 200]
    
    if n % 2:
        print(n)
        print(*[1] * n)
        exit()
    
    
    def search(cur_value, idx, tmp):
        if cur_value % suff_gcd[idx]:
            return 
        
        if idx == 8:
            saved = tmp[:] + [200] * (cur_value // 200)
            
            dp = [0] * (n // 2 + 1)
            dp[0] = 1
            
            for x in saved:
                for i in range(n // 2, x - 1, -1):
                    if dp[i - x]: dp[i] = 1
            
            if dp[n // 2] == 0:
                print(len(saved))
                print(*saved)
                exit()
            
            return 
    
        cnt = fmin(cur_value // bills[idx], bounds[idx])
        search(cur_value, idx + 1, tmp)
        
        for i in range(1, cnt + 1):
            tmp.append(bills[idx])
            search(cur_value - bills[idx] * i, idx + 1, tmp)
        
        for i in range(cnt):
            tmp.pop()
    
    search(n, 0, [])
    
    print('splittable')