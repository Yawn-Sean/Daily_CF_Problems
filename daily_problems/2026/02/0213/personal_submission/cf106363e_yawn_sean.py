# Submission link: https://codeforces.com/gym/106363/submission/362646464
def main(): 
    n = II()
    nums = LII()
    
    pos = [0] * n
    for i in range(n):
        pos[nums[i]] = i
    
    l, r = pos[0], pos[0]
    
    diff_0 = [0] * (n + 1)
    diff_1 = [0] * (n + 1)
    
    for i in range(n):
        l = fmin(l, pos[i])
        r = fmax(r, pos[i])
        
        diff_0[l] += (n - r) * (l + 1)
        diff_0[r + 1] -= (n - r) * (l + 1)
        
        diff_1[0] += n - r
        diff_1[l] -= n - r
        diff_0[0] += n - r
        diff_0[l] -= n - r
    
        diff_1[r + 1] -= l + 1
        diff_1[n] += l + 1
        diff_0[r + 1] += (l + 1) * n
        diff_0[n] -= (l + 1) * n
    
    for i in range(n):
        diff_0[i + 1] += diff_0[i]
        diff_1[i + 1] += diff_1[i]
    
    print('\n'.join(str(diff_1[i] * i + diff_0[i]) for i in range(n)))