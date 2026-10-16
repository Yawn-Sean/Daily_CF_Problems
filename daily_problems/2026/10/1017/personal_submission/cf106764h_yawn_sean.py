# Submission link: https://codeforces.com/gym/106764/submission/394781946
def main():
    n, k = MII()
    nums = LII()
    radius = LII()
    
    farthest = [0] * n
    
    for i in range(n):
        l = fmax(0, i - radius[i])
        r = fmin(n - 1, i + radius[i])
        farthest[l] = fmax(farthest[l], r)
    
    for i in range(1, n):
        farthest[i] = fmax(farthest[i], farthest[i - 1])
    
    diff = [0] * (n + 1)
    
    l, r = 1, 2 * 10 ** 9
    
    while l <= r:
        mid = (l + r) // 2
        
        cur = 0
        total = 0
        flg = True
        
        for i in range(n):
            cur += diff[i]
            v = fmax(mid - (nums[i] + cur), 0)
            
            if v and farthest[i] < i:
                flg = False
                break
            
            diff[farthest[i] + 1] -= v
            cur += v
            total += v
            
            if total > k:
                flg = False
                break
        
        for i in range(n + 1):
            diff[i] = 0
        
        if flg: l = mid + 1
        else: r = mid - 1
    
    print(r)