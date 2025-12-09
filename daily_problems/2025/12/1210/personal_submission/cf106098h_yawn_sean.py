# Submission link: https://codeforces.com/gym/106098/submission/352667195
def main(): 
    def query(x):
        print('?', x, flush=True)
        return I() == 'W'
    
    def answer(x):
        print('!', x, flush=True)
    
    t = II()
    for _ in range(t):
        orig = query(0)
        
        length = 1
        while query(2 * length - 1) == orig:
            length *= 2
        
        l, r = length - 1, 2 * length - 2
        while l <= r:
            mid = (l + r) // 2
            if query(mid) == orig: l = mid + 1
            else: r = mid - 1
        
        rbound = r
        
        length = 1
        while query(-2 * length + 1) == orig:
            length *= 2
        
        l, r = -2 * length + 2, -length + 1
        while l <= r:
            mid = (l + r) // 2
            if query(mid) == orig: r = mid - 1
            else: l = mid + 1
        
        lbound = l
        
        answer(rbound - lbound + 1)