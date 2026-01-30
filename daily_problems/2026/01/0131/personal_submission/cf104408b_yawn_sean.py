# Submission link: https://codeforces.com/gym/104408/submission/360729730
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        x1, y1, x2, y2 = MII()
        
        if x1 == 0 and x2 == 0:
            outs.append(abs(y1 - y2))
        elif y1 == 0 and y2 == 0:
            outs.append(abs(x1 - x2))
        else:
            v1 = abs(x1) + abs(y1)
            v2 = abs(x2) + abs(y2)
            
            if v1 > v2:
                v1, v2 = v2, v1
            
            outs.append(math.pi / 2 * v1 + v2 - v1)
    
    print('\n'.join(map(str, outs)))