# Submission link: https://codeforces.com/gym/106043/submission/340491356
def main():
    n = II()
    nums = LII()
    
    left = [0] * n
    right = [0] * n
    
    stk = [-1]
    
    for i in range(n):
        while stk[-1] != -1 and nums[stk[-1]] <= nums[i]:
            stk.pop()
        
        left[i] = stk[-1]
        stk.append(i)
    
    stk = [n]
    for i in range(n - 1, -1, -1):
        while stk[-1] != n and nums[stk[-1]] <= nums[i]:
            stk.pop()
        right[i] = stk[-1]
        stk.append(i)
    
    max_length = [0] * (n + 1)
    
    for i in range(n):
        if nums[i] < n:
            max_length[nums[i]] = fmax(max_length[nums[i]], right[i] - left[i] - 1)
    
    for i in range(1, n + 1):
        max_length[i] = fmin(max_length[i], max_length[i - 1])
    
    ans = [0] * (n + 1)
    
    for i in range(n + 1):
        ans[max_length[i]] = i + 1
    
    for i in range(n - 1, -1, -1):
        ans[i] = fmax(ans[i], ans[i + 1])
    
    print(' '.join(map(str, ans[1:])))