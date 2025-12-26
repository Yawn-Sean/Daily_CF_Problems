# Submission link: https://codeforces.com/gym/105262/submission/355168420
def main(): 
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        tmp = [-1]
        for x in nums:
            tmp.append(x)
            tmp.append(-1)
        
        wing = [0] * (2 * n + 1)
        idx = 0
        
        for i in range(2 * n + 1):
            if idx + wing[idx] >= i:
                wing[i] = fmin(wing[2 * idx - i], idx + wing[idx] - i)
            
            while i > wing[i] and i + wing[i] < 2 * n and tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1]:
                wing[i] += 1
            
            if wing[i] + i > wing[idx] + idx:
                idx = i
        
        diff_k = [0] * (n + 1)
        diff_b = [0] * (n + 1)
        
        for i in range(2 * n + 1):
            l = (i - wing[i]) // 2
            r = (i + wing[i]) // 2
            
            mid = (l + r + 1) // 2
            diff_k[l] += 1
            diff_k[mid] -= 1
            diff_b[l] -= l - 1
            diff_b[mid] += l - 1
            
            diff_k[mid] -= 1
            diff_k[r] += 1
            diff_b[mid] += r
            diff_b[r] -= r
        
        for i in range(n):
            diff_k[i] %= mod
            diff_b[i] %= mod
            diff_k[i + 1] += diff_k[i]
            diff_b[i + 1] += diff_b[i]
        
        ans = 0
        for i in range(n):
            ans += (diff_k[i] * i + diff_b[i]) % mod * nums[i] % mod
            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))