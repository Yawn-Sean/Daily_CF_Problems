# Submission link: https://codeforces.com/gym/103708/submission/342848418
def main():
    n = II()
    nums = LII()
    mod = 10 ** 9 + 7
    
    acc1 = list(accumulate(nums, initial=0))
    acc2 = list(accumulate((i * nums[i] % mod for i in range(n)), initial=0))
    
    left = [0] * n
    stk = [-1]
    
    for i in range(n):
        while stk[-1] != -1 and nums[stk[-1]] <= nums[i]:
            stk.pop()
        left[i] = stk[-1]
        stk.append(i)
    
    right = [0] * n
    stk = [n]
    
    for i in range(n - 1, -1, -1):
        while stk[-1] != n and nums[stk[-1]] <= nums[i]:
            stk.pop()
        right[i] = stk[-1]
        stk.append(i)
    
    ans = 0
    
    for i in range(n):
        ans += nums[i] * (i - left[i]) % mod * (right[i] - i) % mod
        ans %= mod
        
        ans += (acc2[i] - acc2[left[i] + 1] - (acc1[i] - acc1[left[i] + 1]) * left[i]) % mod * (right[i] - i) % mod
        ans %= mod
        
        ans += ((acc1[right[i]] - acc1[i + 1]) * right[i] - (acc2[right[i]] - acc2[i + 1])) % mod * (i - left[i]) % mod
        ans %= mod
    
    print(ans)