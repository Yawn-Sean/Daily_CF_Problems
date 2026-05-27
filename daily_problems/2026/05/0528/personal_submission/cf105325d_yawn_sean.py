# Submission link: https://codeforces.com/gym/105325/submission/376239831
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        diff = [0] * (n + 1)
        
        for x in nums:
            diff[0] += 1
            diff[fmin(n, x)] -= 1
        
        for i in range(n):
            diff[i + 1] += diff[i]
        
        outs.append(sum(nums) - sum(fmin(nums[i], diff[i]) for i in range(n)))
    
    print('\n'.join(map(str, outs)))