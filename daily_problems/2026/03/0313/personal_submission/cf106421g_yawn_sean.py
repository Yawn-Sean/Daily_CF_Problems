# Submission link: https://codeforces.com/gym/106421/submission/366377016
def main(): 
    n, a, b = MII()
    nums = LII()
    
    ans = 0
    
    acc = [0] * (n + 1)
    
    for i in range(n):
        acc[i + 1] = acc[i] + (nums[i] * n - (b * n + 1))
    
    ans += reversePairs(acc)
    
    for i in range(n):
        acc[i + 1] = acc[i] + (nums[i] * n - a * n)
    
    ans -= reversePairs(acc)
    
    print(ans)