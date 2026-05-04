# Submission link: https://codeforces.com/gym/106414/submission/373498049
def main():
    t = II()
    outs = []
    
    rnd = random.getrandbits(30)
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        for i in range(n):
            nums[i] ^= rnd
        
        pref = [[] for _ in range(n + 1)]
        
        top1 = (0, 0)
        top2 = (1, 0)
        pref[0] = [top1, top2]
        
        cnt = Counter()
    
        for i in range(n):
            cnt[nums[i]] += 1
            cur_freq = cnt[nums[i]]
            
            if nums[i] == top1[0]:
                top1 = (nums[i], cur_freq)
            elif cur_freq > top1[1]:
                top2 = top1
                top1 = (nums[i], cur_freq)
            elif nums[i] == top2[0] or cur_freq > top2[1]:
                top2 = (nums[i], cur_freq)
            
            pref[i + 1] = [top1, top2]
        
        suff = [[] for _ in range(n + 1)]
        
        top1 = (0, 0)
        top2 = (1, 0)
        suff[n] = [top1, top2]
        
        cnt = Counter()
    
        for i in range(n - 1, -1, -1):
            cnt[nums[i]] += 1
            cur_freq = cnt[nums[i]]
            
            if nums[i] == top1[0]:
                top1 = (nums[i], cur_freq)
            elif cur_freq > top1[1]:
                top2 = top1
                top1 = (nums[i], cur_freq)
            elif nums[i] == top2[0] or cur_freq > top2[1]:
                top2 = (nums[i], cur_freq)
            
            suff[i] = [top1, top2]
        
        ans = 0
        for i in range(n + 1):
            for x1, y1 in pref[i]:
                for x2, y2 in suff[i]:
                    if y1 and y2 and x1 != x2:
                        ans = fmax(ans, y1 + y2)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))