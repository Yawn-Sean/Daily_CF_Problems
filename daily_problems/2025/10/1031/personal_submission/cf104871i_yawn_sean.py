# Submission link: https://codeforces.com/gym/104871/submission/346621400
def main(): 
    n = II()
    
    def query(s):
        print('QUERY', s, flush=True)
        return LII()
    
    total_deg = query('1' * n)
    notes = [query(''.join(str(i >> j & 1) for i in range(n))) for j in range(15)]
    
    stk = [i for i in range(n) if total_deg[i] == 1]
    ans = ['ANSWER']
    
    for _ in range(n - 1):
        u = stk.pop()
        v = 0
        for j in range(15):
            if notes[j][u]:
                v |= 1 << j
        
        for j in range(15):
            if u >> j & 1:
                notes[j][v] -= 1
        
        total_deg[v] -= 1
        if total_deg[v] == 1:
            stk.append(v)
        
        ans.append(f'{u + 1} {v + 1}')
    
    print('\n'.join(ans))