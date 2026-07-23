# Submission link: https://codeforces.com/gym/104670/submission/383900242
def main():
    n, c = MII()
    nums = LII()
    
    inf = 10 ** 9
    v1 = inf
    v2 = -inf
    
    ans = [0] * n
    
    for i in range(n):
        v1 = fmin(v1, nums[i] - i * c)
        v2 = fmax(v2, nums[i] + i * c)
        ans[i] = fmax((nums[i] - i * c) - v1, v2 - (nums[i] + i * c))
    
    print(' '.join(map(str, ans)))