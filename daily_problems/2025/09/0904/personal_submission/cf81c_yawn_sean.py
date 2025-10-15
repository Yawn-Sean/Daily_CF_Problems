# Submission link: https://codeforces.com/contest/81/submission/336719623
def main():
    n = II()
    a, b = MII()
    nums = LII()
    
    if a == b:
        print(*([1] * a + [2] * b))
    else:
        ans = [2] * n
        
        to_choose = list(range(n))
        if a > b:
            to_choose.sort(key=lambda x: nums[x])
        else:
            to_choose.sort(key=lambda x: -nums[x])
        
        for i in range(a):
            ans[to_choose[i]] = 1
        
        print(*ans)