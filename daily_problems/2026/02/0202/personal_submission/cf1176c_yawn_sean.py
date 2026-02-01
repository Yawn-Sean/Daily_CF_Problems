# Submission link: https://codeforces.com/contest/1176/submission/360987230
def main(): 
    d = {
        4: 1,
        8: 2,
        15: 3,
        16: 4,
        23: 5,
        42: 6
    }
    
    n = II()
    nums = LII()
    
    cnt = [0] * 7
    cnt[0] = n
    
    for x in nums:
        x = d[x]
        
        if cnt[x - 1]:
            cnt[x - 1] -= 1
            cnt[x] += 1
    
    print(n - 6 * cnt[6])