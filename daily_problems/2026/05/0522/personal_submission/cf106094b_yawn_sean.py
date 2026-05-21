# Submission link: https://codeforces.com/gym/106094/submission/375455434
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, T = MII()
        nums = LII()
        
        score = 50 * n
        total = sum(x // 2 for x in nums)
        
        ans = [0] * n
        
        tmp = []
        for i in range(n):
            tmp.append(nums[i] // 6)
            tmp.append(nums[i] // 3)
    
        for i in sorted(range(2 * n), key=lambda x: tmp[x]):
            if total + tmp[i] <= T:
                score += 25
                total += tmp[i]
                ans[i // 2] += 1
        
        outs.append(str(score))
        outs.append(' '.join(['2', '1.5', '1'][i] for i in ans))
    
    print('\n'.join(outs))