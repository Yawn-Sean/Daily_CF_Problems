# Submission link: https://codeforces.com/gym/106141/submission/374913297
def main():  
    n = II()
    nums = LII()
    
    vals = [1 if x >= 0 else -1 for x in nums]
    st_range = sorted(range(n), key=lambda x: -abs(nums[x]))
    
    total = sum(abs(x) for x in nums)
    val = n
    
    ma_total = total
    ma_val = n
    chosen = 0
    
    for i in range(n):
        total += 2 * abs(nums[st_range[i]])
        val += 8
        
        if total * total * ma_val > ma_total * ma_total * val:
            ma_total = total
            ma_val = val
            chosen = i + 1
    
    for i in range(chosen):
        vals[st_range[i]] *= 3
    
    print(*vals)