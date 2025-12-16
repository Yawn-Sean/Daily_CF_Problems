# Submission link: https://codeforces.com/gym/105870/submission/353677037
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        nums.sort(reverse=True)
        
        cnt = Counter()
        tmp = [[] for _ in range(n)]
        
        for x in nums:
            tmp[cnt[x]].append(x)
            cnt[x] += 1
        
        ans = []
        for v in tmp:
            ans += v
        
        nums.reverse()
        
        outs.append(' '.join(map(str, nums)))
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))