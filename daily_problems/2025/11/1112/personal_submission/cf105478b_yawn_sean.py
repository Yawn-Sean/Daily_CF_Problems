# Submission link: https://codeforces.com/gym/105478/submission/348493576
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = I()
        
        ans = 0
        flg = 0
        
        for i in range(n):
            if s[i] != '?':
                ans += 1
                ans += flg
                flg = 0
            elif i and s[i - 1] != '?':
                if i + 1 < n and s[i + 1] != '?' and s[i - 1] != s[i + 1]:
                    ans += 1
                elif i + 1 < n and s[i + 1] == '?':
                    flg = 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))