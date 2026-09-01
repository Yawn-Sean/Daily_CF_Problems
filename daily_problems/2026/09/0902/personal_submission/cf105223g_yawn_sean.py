# Submission link: https://codeforces.com/gym/105223/submission/389067167
def main():
    n = II()
    nums = LII()
    
    cnt = [0] * 30
    
    for x in nums:
        for i in range(30):
            cnt[i] += x >> i & 1
    
    mod = 10 ** 9 + 7
    pw3 = [1] * (n + 1)
    
    for i in range(n):
        pw3[i + 1] = pw3[i] * 3 % mod
    
    rev2 = (mod + 1) // 2
    
    q = II()
    outs = []
    
    for _ in range(q):
        idx, val = MII()
        idx -= 1
        
        for i in range(30):
            cnt[i] -= nums[idx] >> i & 1
    
        nums[idx] = val
        
        for i in range(30):
            cnt[i] += nums[idx] >> i & 1
        
        ans = 0
        
        for i in range(29, -1, -1):
            ans = (ans * 2 + (pw3[n] - pw3[n - cnt[i]])) % mod
        
        outs.append(ans * rev2 % mod)
    
    print('\n'.join(map(str, outs)))