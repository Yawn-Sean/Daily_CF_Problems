# Submission link: https://codeforces.com/contest/1468/submission/266776525
def main():
    n = II()
    nums = LII()
    
    dp = [0] * (n + 1)
    seg = SegTree(fmax, 0, n + 1)
    
    left_larger = [-1] * n
    stack = [-1]
    
    for i in range(n):
        while stack[-1] != -1 and nums[stack[-1]] < nums[i]:
            stack.pop()
        left_larger[i] = stack[-1]
        stack.append(i)
    
    for i in sorted(range(n), key=lambda x: nums[x]):
        if left_larger[i] != -1:
            dp[i+1] = fmax(seg.prod(0, left_larger[i] + 1) + 2, seg.prod(left_larger[i] + 1, i + 1) + 1)
        else:
            dp[i+1] = seg.prod(0, i + 1) + 1
        seg.set(i+1, dp[i+1])
    print(max(dp))