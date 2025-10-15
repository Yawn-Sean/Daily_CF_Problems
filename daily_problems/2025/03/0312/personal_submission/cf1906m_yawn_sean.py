# Submission link: https://codeforces.com/contest/1906/submission/310182840
def main():
    n = II()
    nums = LII()
    print(fmin(sum(nums) // 3, sum(nums) - max(nums)))