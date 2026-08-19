# Submission link: https://codeforces.com/gym/104017/submission/387667250
def main():
    t = II()
    outs = []
    
    def f(x):
        cb = 0
        stk = []
        
        for c in x:
            if c == 'B': cb ^= 1
            elif stk and stk[-1] == c: stk.pop()
            else: stk.append(c)
        
        return cb, stk
    
    for _ in range(t):
        outs.append('YES' if f(I()) == f(I()) else 'NO')
    
    print('\n'.join(outs))