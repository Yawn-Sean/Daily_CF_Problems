# Submission link: https://codeforces.com/gym/106073/submission/346771712
def main(): 
    n, q = MII()
    nums = LII()
    mod = 10 ** 9 + 7
    rev2 = (mod + 1) // 2
    
    cur = 0
    for v in reversed(nums):
        cur = (cur + v) * rev2 % mod
    
    ans = [0] * (n + 1)
    ans[1] = cur
    
    for v in nums:
        cur = (cur * 2 - v) % mod
        ans[v] += cur * rev2 % mod
        ans[v] %= mod
    
    print(*ans[1:], sep='\n')