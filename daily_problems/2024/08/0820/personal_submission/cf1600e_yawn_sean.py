# Submission link: https://codeforces.com/contest/1600/submission/277243336
def main():
    n = II()
    nums = LII()

    l = 0
    while l < n - 1 and nums[l+1] > nums[l]:
        l += 1

    r = n - 1
    while r > 0 and nums[r-1] > nums[r]:
        r -= 1

    print('Alice' if ((l + 1) | (n - r)) & 1 else 'Bob')