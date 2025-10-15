# Submission link: https://codeforces.com/gym/104380/submission/342707785
def main():
    mod = 10 ** 9 + 7
    
    n, l, r = MII()
    nums = LII()
    
    f = Factorial(n, mod)
    
    pw2 = 1
    rev2 = (mod + 1) // 2
    
    ans = 0
    weight_left = 0
    
    for i in range(l - 1, r):
        weight_left += f.combi(n - 1, i)
        weight_left %= mod
    
    weight_right = weight_left
    
    ans += (weight_left + weight_right) * nums[0] % mod
    
    for i in range(1, n):
        pw2 = pw2 * 2 % mod
        
        weight_left = (weight_left + f.combi(n - i - 1, l - i - 1) - f.combi(n - i - 1, r - i)) % mod * rev2 % mod
        weight_right = (weight_right - f.combi(n - i - 1, l - 2) + f.combi(n - i - 1, r - 1)) % mod * rev2 % mod
        
        ans += (weight_left + weight_right) * nums[i] % mod * pw2 % mod
    
    print(ans % mod)