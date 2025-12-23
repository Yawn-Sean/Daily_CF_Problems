# Submission link: https://codeforces.com/gym/106270/submission/354630938
def main(): 
    M = 10 ** 6
    cost = list(range(M + 1))
    
    cost[1] = 0
    for i in range(2, M + 1):
        if i % 2 and cost[i] == i:
            for j in range(i, M + 1, i * 2):
                cost[j] = i + cost[j // i]
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, a, b = MII()
        nums = LII()
        
        adj0 = []
        adj1 = []
        
        cnt0 = 0
        cnt1 = 0
        
        ans = 0
        
        for i in range(n):
            c1 = 0
            while nums[i] % 2 == 0:
                nums[i] //= 2
                c1 += 2
            
            c0 = cost[nums[i]]
            
            if c0 < c1:
                cnt0 += 1
                ans += c0
                adj1.append(c1 - c0)
            else:
                cnt1 += 1
                ans += c1
                adj0.append(c0 - c1)
        
        adj0.sort()
        adj1.sort()
        
        if cnt0 < a:
            for i in range(a - cnt0):
                ans += adj0[i]
        
        if cnt1 < b:
            for i in range(b - cnt1):
                ans += adj1[i]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))