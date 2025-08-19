# Submission link: https://codeforces.com/contest/1970/submission/334396494
def main():
    n = II()
    nums = LII()
    
    print('YES')
    print('\n'.join(f'{i} {i}' for i in range(1, n + 1)))
    print(' '.join(str(i + nums[i] // 2 + 1) if i + nums[i] // 2 < n else str(i - nums[i] // 2 + 1) for i in range(n)))
