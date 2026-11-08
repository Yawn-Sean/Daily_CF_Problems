# Submission link: https://codeforces.com/gym/106608/submission/397861293
def main():
    def query(p, q):
        print('?', len(p), len(q))
        print(' '.join(f'{x + 1}' for x in p))
        print(' '.join(map(str, q)))
        sys.stdout.flush()
        return II()
    
    def answer(lst):
        print('!', ' '.join(map(str, lst)), flush=True)
    
    t = II()
    
    for _ in range(t):
        n = II()
        ans = [-1] * n
        
        for val in range(n + 1):
            idxs = [i for i in range(n) if ans[i] == -1]
            if len(idxs) == 0: break
            
            q = list(range(val))
            
            pt = 0
            while pt < len(idxs):
                if query(idxs[pt:], q) == val: break
                
                left, right = pt, len(idxs) - 1
                while left <= right:
                    mid = (left + right) // 2
                    if query(idxs[pt:mid + 1], q) == val: left = mid + 1
                    else: right = mid - 1
                
                ans[idxs[left]] = val
                pt = left + 1
        
        answer(ans)