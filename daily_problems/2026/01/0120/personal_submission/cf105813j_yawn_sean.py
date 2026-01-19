# Submission link: https://codeforces.com/gym/105813/submission/358757254
def main(): 
    M = 2 * 10 ** 5
    mod = 10 ** 9 + 7
    f = Factorial(M, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        outs.append(sum(nums) % mod * f.inv(n) % mod)
    
    print('\n'.join(map(str, outs)))