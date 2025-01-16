# Submission link: https://codeforces.com/contest/831/submission/301172241
def main():
    n, k = MII()
    nums = LII()
    target = LII()
    
    for i in range(1, n):
        nums[i] += nums[i - 1]
    
    st = set(nums)
    
    ans = 0
    for v in st:
        start = target[0] - v
        flg = True
        
        for x in target:
            if x - start not in st:
                flg = False
        
        if flg: ans += 1
    
    print(ans)