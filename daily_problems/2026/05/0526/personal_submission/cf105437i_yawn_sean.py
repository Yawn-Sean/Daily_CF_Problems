# Submission link: https://codeforces.com/gym/105437/submission/376005972
def main():
    n, m = MII()
    nums = LII()
    
    cur = 0
    dp = [0]
    diff = [0] * 2
    
    def update():
        global cur
        cur += 1
        
        for i in range(cur):
            diff[i + 1] += diff[i]
        
        for i in range(cur):
            dp[i] += diff[i]
            diff[i] = 0
    
    for x in nums:
        if x == 0:
            update()
            
            dp.append(0)
            diff.append(0)
            
            for i in range(cur, 0, -1):
                dp[i] = fmax(dp[i], dp[i - 1])
        
        elif x > 0:
            if x <= cur:
                diff[x] += 1
                diff[cur + 1] -= 1
        
        else:
            if -x <= cur:
                diff[0] += 1
                diff[cur + x + 1] -= 1
    
    update()
    print(max(dp))