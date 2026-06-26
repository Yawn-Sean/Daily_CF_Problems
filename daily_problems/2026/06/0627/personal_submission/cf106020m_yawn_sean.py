# Submission link: https://codeforces.com/gym/106020/submission/380184856
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        outs.append(sum(nums) ^ sum(nums[1:]) ^ sum(nums[:-1]) ^ sum(nums[1:-1]))
    
    print('\n'.join(map(str, outs)))