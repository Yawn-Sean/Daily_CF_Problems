# Submission link: https://codeforces.com/gym/106073/submission/346814055
def main(): 
    n, q = MII()
    nums = LII()
    mod = 10 ** 9 + 7
    rev2 = (mod + 1) // 2
    
    ans = [0] * (n + 1)
    
    cur = 0
    for v in reversed(nums):
        ans[v] = (ans[v] + cur * rev2) % mod
        cur = (cur + v) * rev2 % mod
    
    ans[1] = (ans[1] + cur) % mod
    
    print(*ans[1:], sep='\n')