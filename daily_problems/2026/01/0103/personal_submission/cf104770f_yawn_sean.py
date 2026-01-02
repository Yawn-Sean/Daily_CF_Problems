# Submission link: https://codeforces.com/gym/104770/submission/356129169
def main(): 
    n = II()
    nums = LII()
    nums.sort()
    
    cnt = [0] * n
    
    for x in nums:
        cnt[bisect.bisect_left(nums, x)] += 1
    
    vals = [[] for _ in range(n)]
    c = 0
    
    for i in range(n):
        if cnt[i]:
            vals[i].append(nums[i])
            cnt[i] -= 1
            c += 1
    
    if 2 * c - 1 != n: print(-1)
    else:
        cur = (n + 1) // 2
        
        while cur > 1:
            p1 = [i for i in range(n) if cnt[i]]
            p2 = [i for i in range(n) if cnt[i] == 0 and vals[i]]
            
            if len(p1) != len(p2):
                exit(print(-1))
            
            for x, y in zip(p1, p2):
                if x > y: exit(print(-1))
                vals[x].extend(vals[y])
                vals[y].clear()
                cnt[x] -= 1
    
            cur = (cur + 1) // 2
        
        print(*vals[0])