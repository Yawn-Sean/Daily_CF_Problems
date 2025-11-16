# Submission link: https://codeforces.com/gym/106191/submission/349226949
def main(): 
    def query(S, T):
        print('?', len(S), *(i + 1 for i in S), len(T), *(i + 1 for i in T), flush=True)
        return II()
    
    def answer(x):
        print('!', x, flush=True)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        
        total_edge = query(list(range(n)), list(range(n)))
        degs = [0] * n
        
        for i in range(n - 1):
            tmp = [j for j in range(n) if j != i]
            degs[i] = total_edge - query(tmp, tmp)
        
        degs[-1] = total_edge * 2 - sum(degs)
        
        if 1 in degs: answer(degs.index(1) + 1)
        else: answer(-1)