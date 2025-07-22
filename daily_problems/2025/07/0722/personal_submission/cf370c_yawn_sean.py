# Submission link: https://codeforces.com/contest/370/submission/330141056
def main():
    n, k = MII()
    nums = LII()
    
    cnt = [0] * (k + 1)
    for v in nums:
        cnt[v] += 1
    
    ma = max(cnt)
    
    nums.sort()
    
    print(fmin(n, 2 * n - 2 * ma))
    print('\n'.join(f'{nums[i]} {nums[(i + ma) % n]}' for i in range(n)))