# Submission link: https://codeforces.com/gym/103503/submission/366131974
def main(): 
    n, s = MII()
    nums = LII()
    
    nums.sort()
    cur = sum(nums)
    
    acc = list(accumulate(nums, initial=0))
    
    l, r = 0, 2 * 10 ** 9
    
    while l <= r:
        mid = (l + r) // 2
        pos = bisect.bisect_left(nums, mid)
        if cur + (mid + 1) * mid // 2 - acc[pos] >= s:
            r = mid - 1
        else:
            l = mid + 1
    
    print(l - bisect.bisect_left(nums, l) + n)
