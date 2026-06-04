# Submission link: https://codeforces.com/gym/102860/submission/377278085
def main():
    n, l = MII()
    nums = LII()
    nums.sort()
    
    for i in range(n):
        nums.append(nums[i] + l)
    
    ans = n * (n - 1) * (n - 2) // 6
    r = 0
    
    for i in range(n):
        while 2 * (nums[r] - nums[i]) < l:
            r += 1
        
        v = r - i - 1
        ans -= v * (v - 1) // 2
    
    print(ans)