# Submission link: https://codeforces.com/gym/102964/submission/387888224
def main():
    n, x, k = MII()
    nums = LII()
    
    mod = 10 ** 9 + 7
    
    if k:
        total = (n - 1) * pow(2, k, mod) % mod
        print((total + 1 - total * pow(x, -1, mod)) % mod)
    
    else:
        print(sum(nums[i] != nums[i - 1] for i in range(1, n)) + 1)