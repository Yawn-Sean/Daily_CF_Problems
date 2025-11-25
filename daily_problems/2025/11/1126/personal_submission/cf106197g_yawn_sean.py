# Submission link: https://codeforces.com/gym/106197/submission/350583720
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        s = [int(c) for c in I()]
        
        if 0 not in s: outs.append('0')
        else:
            n = len(s)
    
            next_pos = [[n] * (n + 1) for _ in range(10)]
            
            for i in range(n - 1, -1, -1):
                for j in range(10):
                    next_pos[j][i] = next_pos[j][i + 1]
                next_pos[s[i]][i] = i
    
            later_longest_full = [0] * (n + 1)
            later_longest_full[n] = -1
            
            cnt = [0] * 10
            cur = 0
            res = 0
            
            for i in range(n - 1, -1, -1):
                later_longest_full[i] = res
    
                if cnt[s[i]] == 0:
                    cnt[s[i]] = 1
                    cur += 1
                
                if cur == 10:
                    cur = 0
                    res += 1
                    for j in range(10):
                        cnt[j] = 0
    
            ans = []
            pos = 0
            
            while pos <= n:
                mi = n + 5
                choice = -1
    
                for i in range(0 if ans else 1, 10):
                    if later_longest_full[next_pos[i][pos]] < mi:
                        mi = later_longest_full[next_pos[i][pos]]
                        choice = i
                
                ans.append(choice)
                pos = next_pos[choice][pos] + 1
            
            outs.append(''.join(map(str, ans)))
    
    print('\n'.join(outs))