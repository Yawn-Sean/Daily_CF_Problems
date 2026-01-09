# Submission link: https://codeforces.com/gym/106296/submission/357052646
def main(): 
    n = II()
    nums = LII()
    
    mod = 998244353
    
    ans = 1
    cur = 0
    
    for i in range(n):
        if nums[i]: cur += 1
        else:
            ans = ans * cur % mod
            cur -= 1
    
    cur = 0
    for i in range(n - 1, n % 2 - 1, -1):
        if nums[i]:
            ans = ans * cur % mod
            cur -= 1
        else:
            cur += 1
    
    print(ans)