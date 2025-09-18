# Submission link: https://codeforces.com/gym/104182/submission/339205691
def main():
    n = II()
    nums = LII()
    
    ans = 1 + n * (n + 1) // 2
    
    stk = [-1]
    for i in range(n):
        while stk[-1] != -1 and nums[i] >= nums[stk[-1]]:
            stk.pop()
        ans -= i - stk[-1]
        stk.append(i)
    
    stk = [n]
    for i in range(n - 1, -1, -1):
        while stk[-1] != n and nums[i] <= nums[stk[-1]]:
            stk.pop()
        ans -= stk[-1] - i
        stk.append(i)
    
    stk1 = [n]
    stk2 = [n]
    
    for i in range(n - 1, -1, -1):
        while stk1[-1] != n and nums[i] > nums[stk1[-1]]:
            stk1.pop()
        
        while stk2[-1] != n and nums[i] <= nums[stk2[-1]]:
            stk2.pop()
        
        l, r = 0, len(stk1) - 1
        while l <= r:
            mid = (l + r) // 2
            if stk1[mid] >= stk2[-1]: l = mid + 1
            else: r = mid - 1
        
        ans += len(stk1) - l + 1
        
        stk1.append(i)
        stk2.append(i)
    
    print(ans)