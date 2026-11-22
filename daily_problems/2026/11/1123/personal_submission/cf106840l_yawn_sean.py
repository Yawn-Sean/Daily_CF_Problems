# Submission link: https://codeforces.com/gym/106840/submission/399482676
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        a, b = MII()
        
        if a < b: a, b = b, a
        
        if a == b: outs.append('-1')
        elif 360 % (a - b): outs.append('-1')
        else:
            n = 360 // (a - b)
            
            area = 0
            area += math.sin(a / 180 * math.pi) / 2
            area += math.cos(a / 2 / 180 * math.pi) ** 2 / math.tan(math.pi / n)
            area *= n
            
            outs.append(f'{area:.10f}')
    
    print('\n'.join(outs))