# Submission link: https://codeforces.com/contest/1906/submission/330142305
def main():
    n = II()
    nums = LII()
    
    intervals = []
    
    l = 0
    
    while l < n * 2:
        r = l
        while r + 1 < n * 2 and nums[r + 1] < nums[l]:
            r += 1
        intervals.append((l, r))
        l = r + 1
    
    dp = [-2] * (n + 1)
    dp[0] = -1
    
    for i in range(len(intervals)):
        x = intervals[i][1] - intervals[i][0] + 1
        for y in range(n, x - 1, -1):
            if dp[y - x] != -2 and dp[y] == -2:
                dp[y] = i
    
    if dp[n] == -2:
        exit(print(-1))
    
    choice = [0] * (2 * n)
    cur = n
    
    while cur:
        idx = dp[cur]
        l, r = intervals[idx]
        
        for i in range(l, r + 1):
            choice[i] = 1
        
        cur -= r - l + 1
    
    print(' '.join(str(nums[i]) for i in range(2 * n) if choice[i]))
    print(' '.join(str(nums[i]) for i in range(2 * n) if not choice[i]))