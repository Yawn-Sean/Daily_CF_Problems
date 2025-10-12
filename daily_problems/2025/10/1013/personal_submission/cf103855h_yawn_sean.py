# Submission link: https://codeforces.com/gym/103855/submission/343295091
def main():
    n = II()
    nums = LII()
    
    mod = 10 ** 9 + 7
    
    cur = 0
    pos = 0
    
    ans = 1
    
    for i in range(n):
        if nums[i] > cur:
            ans = ans * (i - pos + 1) % mod
            cur = nums[i]
            pos = i
    
    print(ans)