# Submission link: https://codeforces.com/contest/89/submission/318389244
def main():
    n, m, k = MII()
    nums = LII()

    if n % 2 == 0: print(0)
    else: print(fmin(min(nums[::2]), m // (n // 2 + 1) * k))