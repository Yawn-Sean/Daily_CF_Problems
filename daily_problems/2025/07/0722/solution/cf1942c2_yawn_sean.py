# Submission link: https://codeforces.com/contest/1942/submission/330292048
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, x, y = MII()
        nums = LII()
        nums.sort()
        
        vs = []
        cnt = x
        
        for i in range(1, x):
            v = nums[i] - nums[i - 1] - 1
            if v % 2:
                vs.append(v)
        
        v = nums[0] + n - nums[-1] - 1
        if v % 2:
            vs.append(v)
        
        vs.sort()
        for x in vs:
            if y >= x // 2:
                y -= x // 2
                cnt += x
    
        cnt = fmin(n, cnt + y * 2)
        outs.append(cnt - 2)
    
    print('\n'.join(map(str, outs)))