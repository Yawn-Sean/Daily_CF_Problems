# Submission link: https://codeforces.com/gym/102129/submission/388529603
def main():
    n = II()
    nums = LII()
    mod = 10 ** 9 + 7
    
    print((nums[0] - nums[1] + mod) % mod)