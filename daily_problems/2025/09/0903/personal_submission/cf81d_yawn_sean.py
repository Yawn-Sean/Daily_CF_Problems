# Submission link: https://codeforces.com/contest/81/submission/336617526
def main():
    n, m = MII()
    nums = LII()
    
    for i in range(m):
        nums[i] = fmin(nums[i], n // 2)
    
    total = []
    
    for i in sorted(range(m), key=lambda x: -nums[x]):
        while len(total) < n and nums[i]:
            total.append(i + 1)
            nums[i] -= 1
    
    if len(total) < n:
        exit(print(-1))
    
    ans = [0] * n
    
    pt = 0
    for x in total:
        ans[pt] = x
        pt += 2
        
        if pt >= n:
            pt = 1
    
    print(*ans)