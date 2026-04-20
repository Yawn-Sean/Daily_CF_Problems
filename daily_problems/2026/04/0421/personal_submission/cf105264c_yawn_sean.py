# Submission link: https://codeforces.com/gym/105264/submission/371848926
def main():
    t = II()
    outs = []
    
    inf = 10 ** 13
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        nums.sort()
        
        acc = [0] * (n + 1)
        for i in range(n):
            acc[i + 1] = acc[i] + nums[i]
    
        dp = [inf] * (n + 1)
        dp[0] = 0
        
        for i in range(1, n + 1):
            ndp = [inf] * (n + 1)
            
            for x in range(n):
                for y in range(x, n):
                    mid = (x + y) // 2
                    cost = ((acc[y + 1] - acc[mid]) - (y + 1 - mid) * nums[mid]) + ((mid - x) * nums[mid] - (acc[mid] - acc[x]))
                    ndp[y + 1] = fmin(ndp[y + 1], dp[x] + cost)
            
            if ndp[-1] <= k:
                outs.append(i)
                break
            
            dp = ndp
    
    print('\n'.join(map(str, outs)))