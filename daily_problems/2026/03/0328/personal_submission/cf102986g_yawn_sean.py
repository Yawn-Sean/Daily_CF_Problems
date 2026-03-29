# Submission link: https://codeforces.com/gym/102986/submission/368386747
def main(): 
    n, w = MII()
    nums = LII()
    nums.sort()
    
    ans = 0
    for i in range(n):
        ans += (2 * i - (n - 1)) * nums[i]
    
    print(ans * 2 / n + w)