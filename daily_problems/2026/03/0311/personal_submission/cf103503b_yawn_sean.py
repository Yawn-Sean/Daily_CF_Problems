# Submission link: https://codeforces.com/gym/103503/submission/366133343
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, idx = MII()
        ans = -1
        
        l, r = 1, n
        cur = 1
        last_cnt = 0
        cnt = 1
        
        while cnt <= n:
            mid = (l + r) // 2
            
            if idx >= mid: last_cnt = last_cnt * 2 + 1
            else: last_cnt = last_cnt * 2
            
            if idx == mid:
                ans = cur
                break
            
            if idx < mid:
                r = mid - 1
                cur = cur * 2
            else:
                l = mid + 1
                cur = cur * 2 + 1
            
            cnt = cnt * 2 + 1
        
        if ans == -1:
            ans = idx + cnt // 2 - last_cnt
        
        outs.append(ans)
    
    print(' '.join(map(str, outs)))
