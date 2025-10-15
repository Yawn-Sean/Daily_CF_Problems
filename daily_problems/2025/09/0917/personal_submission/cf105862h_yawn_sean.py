# Submission link: https://codeforces.com/gym/105862/submission/338866645
def main():
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        total = sum(nums)
        times = 0
        for i in range(n):
            g = math.gcd(n, i)
            times += n // g
        
        rev_n = pow(n, -1, mod)
        outs.append(sum(nums) * times % mod * rev_n % mod * rev_n % mod)
    
    print('\n'.join(map(str, outs)))