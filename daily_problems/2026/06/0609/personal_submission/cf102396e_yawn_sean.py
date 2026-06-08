# Submission link: https://codeforces.com/gym/102396/submission/377743388
def main():
    n = II()
    nums = LII()
    
    cur = 1 << n - 1
    m = 0
    
    ans = [0] * n
    
    for i in range(n):
        if nums[i]:
            ans[i] = cur // nums[i]
            m += cur
            cur //= 2
    
    for i in range(n):
        if nums[i] == 0:
            ans[i] = cur
            cur //= 2
    
    print(m)
    print(*ans)