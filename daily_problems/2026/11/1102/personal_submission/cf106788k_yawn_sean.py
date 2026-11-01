# Submission link: https://codeforces.com/gym/106788/submission/397001629
def main(): 
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    tags = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    ans = 5
    chosen_msk = 0
    
    for i in range(16):
        flg = True
        
        for j in range(n):
            nflg = False
            
            for k in range(4):
                if i >> k & 1:
                    dx, dy = tags[k]
                    if xs[j] * dx + ys[j] * dy > 0:
                        nflg = True
            
            if not nflg:
                flg = False
        
        if flg and i.bit_count() < ans:
            ans = i.bit_count()
            chosen_msk = i
    
    chosen = [chosen_msk >> i & 1 for i in range(4)]
    
    ans = []
    
    if chosen[0]:
        if chosen[3]:
            ans.append('-0.4 0.6 1500.0 0.6 -0.4 1500.0 1500.0 1500.0')
        else:
            ans.append('-1500.0 0.6 1500.0 0.6 -1500.0 1500.0 1500.0 1500.0')
    
    if chosen[1]:
        if chosen[0]:
            ans.append('0.6 0.4 1500.0 0.4 0.6 -1500.0 1500.0 -1500.0')
        else:
            ans.append('0.6 1500.0 1500.0 1500.0 0.6 -1500.0 1500.0 -1500.0')
    
    if chosen[2]:
        if chosen[1]:
            ans.append('-1500.0 -0.6 0.4 -0.6 -1500.0 -1500.0 0.4 -1500.0')
        else:
            ans.append('-1500.0 -0.6 1500.0 -0.6 -1500.0 -1500.0 1500.0 -1500.0')
    
    if chosen[3]:
        if chosen[2]:
            ans.append('-1500.0 -0.4 -0.6 -0.4 -1500.0 1500.0 -0.6 1500.0')
        else:
            ans.append('-1500.0 -1500.0 -0.6 -1500.0 -1500.0 1500.0 -0.6 1500.0')
    
    print(len(ans))
    print('\n'.join(ans))