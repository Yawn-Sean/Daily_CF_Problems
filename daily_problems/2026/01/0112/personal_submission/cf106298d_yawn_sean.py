# Submission link: https://codeforces.com/gym/106298/submission/357298824
def main(): 
    M = 10 ** 6
    pr = list(range(M + 1))
    
    for i in range(2, M + 1):
        if pr[i] == i:
            for j in range(i, M + 1, i):
                pr[j] = i
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        ls = LII()
        rs = LII()
        
        to_check = -1
        for i in range(n):
            if ls[i] == rs[i]:
                to_check = ls[i]
        
        if to_check == -1:
            outs.append('YES')
            outs.append(' '.join(str(rs[i] // 2 * 2) for i in range(n)))
        
        else:
            prs = set()
            
            while to_check > 1:
                prs.add(pr[to_check])
                to_check //= pr[to_check]
            
            for p in prs:
                flg = True
                for i in range(n):
                    if rs[i] // p * p < ls[i]:
                        flg = False
                
                if flg:
                    outs.append('YES')
                    outs.append(' '.join(str(rs[i] // p * p) for i in range(n)))
                    break
            else:
                outs.append('NO')
    
    print('\n'.join(outs))