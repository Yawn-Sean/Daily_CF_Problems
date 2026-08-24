# Submission link: https://codeforces.com/gym/102760/submission/388215070
def main():
    n = II()
    nums = LII()
    
    nums.sort()
    
    mn = sum(nums[:n - 1])
    mx = 0
    
    for i in range(1, n):
        mx += nums[i * (i - 1) // 2]
    
    print(mn, mx)