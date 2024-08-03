# Submission link: https://codeforces.com/contest/1671/submission/263395256
def main():
    n, x = MII()
    nums = LII()
    
    ans = 0
    for i in range(1, n):
        ans += abs(nums[i] - nums[i-1])
    
    v = min(nums[0], nums[-1]) - 1
    v = min(v, 2 * min(nums) - 2)
    ans += v
    
    v = x - max(nums[0], nums[-1])
    v = min(v, 2 * x - 2 * max(nums))
    ans += max(v, 0)
    outs.append(ans)