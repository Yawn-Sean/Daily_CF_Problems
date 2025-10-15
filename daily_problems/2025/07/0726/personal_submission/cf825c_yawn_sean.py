# Submission link: https://codeforces.com/contest/825/submission/330814310
def main():
    n, k = MII()
    nums = LII()
    nums.sort()
    
    ans = 0
    
    for x in nums:
        while 2 * k < x:
            k *= 2
            ans += 1
        
        k = fmax(x, k)
    
    print(ans)