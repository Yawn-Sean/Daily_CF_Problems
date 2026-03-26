# Submission link: https://codeforces.com/gym/106439/submission/368272709
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        ans = 0
        
        for i in range(1, n + 1):
            m_bound = fmin(i - 1, m)
            x = i
            vals = []
    
            while x:
                v = x & -x
                vals.append(v)
                x -= v
            
            if m_bound < vals[-1]: continue
            
            cur = vals[-1]
            ans += 1
            
            for j in range(len(vals) - 2, -1, -1):
                if cur + vals[j] <= m_bound:
                    cur += vals[j]
                    ans += 1 << j
        
        n, m = m, n
        
        for i in range(1, n + 1):
            m_bound = fmin(i - 1, m)
            x = i
            vals = []
    
            while x:
                v = x & -x
                vals.append(v)
                x -= v
            
            if m_bound < vals[-1]: continue
            
            cur = vals[-1]
            ans += 1
            
            for i in range(len(vals) - 2, -1, -1):
                if cur + vals[i] <= m_bound:
                    cur += vals[i]
                    ans += 1 << i
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))