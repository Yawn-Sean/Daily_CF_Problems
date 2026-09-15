# Submission link: https://codeforces.com/gym/106706/submission/390791041
def main():
    def query(idxs):
        print('?', len(idxs), *idxs, flush=True)
        return II()
    
    n = II()
    saved = [0] * (n + 1)
    
    is_t = 1
    is_f = 1
    
    for i in range(2, n + 1):
        saved[i] = query([1, i])
        
        if saved[i] == 0: is_t = 0
        elif saved[i] == 2: is_f = 0
    
    ans = [''] * (n + 1)
    
    if is_t:
        ans[1] = 'T'
        f = -1
        
        for i in range(2, n + 1):
            if saved[i] == 1:
                ans[i] = 'F'
                f = i
        
        for i in range(2, n + 1):
            if f != i and saved[i] == 2:
                ans[i] = 'T' if query([f, i]) == 1 else 'M'
    
    else:
        ans[1] = 'F' if is_f else 'M'
        t = -1
        
        for i in range(2, n + 1):
            if saved[i]:
                ans[i] = 'T'
                t = i
        
        for i in range(2, n + 1):
            if t != i and saved[i] == 0:
                ans[i] = 'F' if query([t, i]) == 1 else 'M'
    
    print('!', ''.join(ans))