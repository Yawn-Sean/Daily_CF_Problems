# Submission link: https://codeforces.com/gym/106628/submission/384312802
def main():
    def query(idxs):
        print('?', len(idxs), *idxs, flush=True)
        return II()
    
    def answer(p):
        print('!', *p, flush=True)
    
    t = II()
    
    for _ in range(t):
        n = II()
        cur = 0
        
        ans = [0] * n
        ans[0] = 1
        
        for i in range(2, n + 1):
            ncur = query(list(range(1, i + 1)))
            val = i - (ncur - cur)
            
            for j in range(i):
                if ans[j] >= val:
                    ans[j] += 1
            ans[i - 1] = val
            
            cur = ncur
    
        answer(ans)