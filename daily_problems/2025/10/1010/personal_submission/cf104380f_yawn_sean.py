# Submission link: https://codeforces.com/gym/104380/submission/342707785
def main():
    n, l, r = MII()
    nums = LII()
    
    v = fmin(l - 1, n - r)
    nums = nums[:n - v]
    print(sum(nlargest(r - l + 1, nums)))