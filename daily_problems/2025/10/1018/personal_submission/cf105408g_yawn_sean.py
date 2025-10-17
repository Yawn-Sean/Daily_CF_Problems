# Submission link: https://codeforces.com/gym/105408/submission/344183048
def main(): 
    n = II()
    nums = LII()
    g = math.gcd(*nums)
    
    for i in range(n):
        nums[i] //= g
    
    M = max(nums)
    prime_factor = list(range(M + 1))
    
    for i in range(2, M + 1):
        if prime_factor[i] == i:
            for j in range(i, M + 1, i):
                prime_factor[j] = i
    
    vis = [0] * (M + 1)
    
    for x in nums:
        while x > 1:
            p = prime_factor[x]
            if vis[p]: exit(print('NO'))
            vis[p] = 1
            while x % p == 0:
                x //= p
    
    print('YES')