# Submission link: https://codeforces.com/gym/105018/submission/357658953
def main(): 
    def prep(p):
        pi = [0] * len(p)
        j = 0
        for i in range(1, len(p)):
            while j != 0 and p[j] != p[i]:
                j = pi[j - 1]
            if p[j] == p[i]:
                j += 1
            pi[i] = j
        return pi
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = [int(c) for c in I()]
        
        s.append(-1)
        for i in range(n):
            s.append(s[i] ^ 1)
        
        outs.append(' '.join(map(str, prep(s)[n + 1:])))
    
    print('\n'.join(map(str, outs)))