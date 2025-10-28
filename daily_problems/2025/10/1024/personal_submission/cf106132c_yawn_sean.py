# Submission link: https://codeforces.com/gym/106132/submission/345309588
def main(): 
    n, m, k = MII()
    nums = LII()
    
    vis = set(nums)
    cnt = Counter()
    
    for x in nums:
        cnt[x] ^= 1
        cnt[(k - x * x) % m] ^= 1
    
    if sum(cnt.values()) > 2:
        exit(print('NO'))
    
    for x in cnt:
        if cnt[x]:
            ans = [x]
            for i in range(n - 1):
                ans.append((k - ans[-1] * ans[-1]) % m)
            
            if sorted(ans) == sorted(nums):
                ans.reverse()
                print('YES')
                exit(print(*ans))
    
    ans = [nums[0]]
    for i in range(n - 1):
        ans.append((k - ans[-1] * ans[-1]) % m)
    
    
    if sorted(ans) == sorted(nums):
        ans.reverse()
        print('YES')
        exit(print(*ans))
    
    print('NO')