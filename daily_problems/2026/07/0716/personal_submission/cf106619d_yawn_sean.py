# Submission link: https://codeforces.com/gym/106619/submission/382787548
def main():
    def query(m, v):
        print('?', m, v, flush=True)
        return II()
    
    def answer(x, y):
        print('!', x, y, flush=True)
    
    t = II()
    outs = []
    
    for _ in range(t):
        xor_val = 0
        
        for i in range(60):
            if query(1 << i, 1 << i):
                xor_val |= 1 << i
    
        v = xor_val & -xor_val
        
        for i in range(60):
            if v >> i & 1: continue
            nv = v | (1 << i)
            if query(nv, nv):
                v = nv
        
        x = v
        y = x ^ xor_val
        
        if x > y: x, y = y, x
        
        answer(x, y)