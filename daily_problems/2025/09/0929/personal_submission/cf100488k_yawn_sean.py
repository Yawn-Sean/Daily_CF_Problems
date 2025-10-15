# Submission link: https://codeforces.com/gym/100488/submission/340841958
def main():
    n = II()
    nums = LII()
    
    having = []
    
    for i in range(n):
        cur = i // 2 + 1
        
        if len(having) < cur:
            heappush(having, nums[i])
        elif having[0] < nums[i]:
            heapreplace(having, nums[i])
    
    v = sum(having)
    print(v, sum(nums) - v)