# Submission link: https://codeforces.com/contest/1175/submission/259434311
def main():
    n, k = MII()
    nums = LII()
    
    x, ans = -1, 10 ** 9
    for i in range(n - k):
        if nums[i+k] - nums[i] < ans:
            ans = nums[i+k] - nums[i]
            x = (nums[i+k] + nums[i]) // 2
    print(x)