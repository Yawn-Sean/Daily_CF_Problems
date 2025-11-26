# Submission link: https://codeforces.com/gym/106197/submission/350730520
def main(): 
    def query(x, y):
        print('?', x, y, flush=True)
        return II()
    
    def answer(idxs):
        print('!', len(idxs), *(idx for idx in idxs))
    
    n = II()
    pos1 = 1
    
    for i in range(2, n + 1):
        if query(pos1, i) != pos1:
            pos1 = i
    
    cur = [i for i in range(1, n + 1) if i != pos1]
    ans = []
    
    while cur:
        ncur = []
        prime_val = cur[0]
    
        for i in range(1, len(cur)):
            v = query(prime_val, cur[i])
            
            if v == pos1: ncur.append(cur[i])
            elif v == cur[i]: prime_val = cur[i]
        
        cur = ncur
        ans.append(prime_val)
    
    answer(ans)