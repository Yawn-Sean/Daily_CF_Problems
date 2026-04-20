# Submission link: https://codeforces.com/gym/105264/submission/371848405
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = [int(c) for c in I()]
        
        if n == 1: outs.append('0 0')
        else:
            ans = sum(s) * 11
            x, y = nlargest(2, s)
            ans -= x * 10
            ans -= y
            
            cnt = 0
            if s[0] != y: cnt += 1
            if s[-1] != x: cnt += 1
            
            if s[0] == x and s[-1] == y:
                cnt = fmin(cnt, 1)
            
            outs.append(f'{cnt} {ans}')
    
    print('\n'.join(outs))