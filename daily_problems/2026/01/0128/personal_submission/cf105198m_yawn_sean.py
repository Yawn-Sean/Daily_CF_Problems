# Submission link: https://codeforces.com/gym/105198/submission/360103662
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        sx, sy, tx, ty, k = MII()
        dx = abs(sx - tx)
        dy = abs(sy - ty)
        
        if dx < dy: dx, dy = dy, dx
        
        if dx <= (dy + 1) * k:
            outs.append(dx + dy)
        else:
            other = (dx - (dy + 1) * k + 2 * k - 1) // (2 * k) * 2
            outs.append(dx + dy + other)
    
    print('\n'.join(map(str, outs)))