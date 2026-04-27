# Submission link: https://codeforces.com/gym/106501/submission/372679830
def main():
    def query(l, r):
        print('?', l + 1, r + 1, flush=True)
        return II()
    
    def answer(p):
        print('!', p + 1)
    
    n = II()
    
    if query(0, 0):
        answer(0)
    else:
        block = 1
        l_bound = 1
        r_bound = 1
        for i in range(1, 30):
            r = 1 << i
            l = r // 2
            
            if r >= n:
                r_bound = n - 1
                break
            
            block = r - l
            if query(l, r - 1):
                r_bound = r - 1
                break
            
            l_bound = r
        
        l = l_bound
        r = r_bound
        
        while l <= r:
            mid = (l + r) // 2
            if query(mid - block + 1, mid): r = mid - 1
            else: l = mid + 1
        
        answer(l)