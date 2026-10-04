# Submission link: https://codeforces.com/gym/106733/submission/392900616
def main():
    n, m, k = MII()
    nums = LII()
    
    max_full_cups = [0] * n
    
    for i in range(n):
        nums[i] = fmin(nums[i], k * (k + 1) // 2)
        l, r = 1, k
        while l <= r:
            mid = (l + r) // 2
            if (2 * k - mid + 1) * mid // 2 <= nums[i]: l = mid + 1
            else: r = mid - 1
        max_full_cups[i] = r
    
    l, r = 1, k
    
    while l <= r:
        mid = (l + r) // 2
        total = 0
        
        for i in range(n):
            x = max_full_cups[i]
            if mid >= k + 1 - x:
                total += k - mid + 1
            else:
                total += x
                if nums[i] - (2 * k - x + 1) * x // 2 >= mid:
                    total += 1
        
            if total >= m: break
        
        if total >= m: l = mid + 1
        else: r = mid - 1
    
    ans = 0
    total = 0
    
    for i in range(n):
        x = max_full_cups[i]
        if r >= k + 1 - x:
            total += k - r + 1
            ans += (k + r) * (k - r + 1) // 2
        else:
            total += x
            ans += (2 * k - x + 1) * x // 2
            
            if nums[i] - (2 * k - x + 1) * x // 2 >= r:
                total += 1
                ans += nums[i] - (2 * k - x + 1) * x // 2
    
    print(ans + (m - total) * r)