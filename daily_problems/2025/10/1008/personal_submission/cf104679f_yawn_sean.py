# Submission link: https://codeforces.com/gym/104679/submission/342417492
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        a, b = MII()
        
        if a | b != a: outs.append('-1')
        else:
            vals = [i for i in range(a + 1) if i & a == i]
            xor_val = reduce(xor, vals) ^ b
            
            if xor_val: vals.remove(xor_val)
            
            if reduce(ior, vals) == a:
                outs.append(str(len(vals)))
                outs.append(' '.join(map(str, vals)))
            else:
                outs.append('-1')
    
    print('\n'.join(outs))