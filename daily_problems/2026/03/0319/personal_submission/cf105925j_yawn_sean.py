# Submission link: https://codeforces.com/gym/105925/submission/367232384
def main(): 
    n, k = MII()
    nums = LII()
    
    for i in range(n):
        nums.append(nums[i])
    
    for i in range(2 * n):
        nums[i] -= i * k
    
    ans = [0] * n
    
    stk = []
    for i in range(2 * n - 1, -1, -1):
        while stk and nums[stk[-1]] >= nums[i]:
            stk.pop()
        if i < n: ans[i] = stk[-1] % n + 1
        stk.append(i)
    
    print(' '.join(map(str, ans)))