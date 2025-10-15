# Submission link: https://codeforces.com/contest/1468/submission/308210789
def main():
    d = {
        'L': (-1, 0), 
        'R': (1, 0),
        'D': (0, -1),
        'U': (0, 1)
    }

    t = II()
    outs = []

    for _ in range(t):
        s = I()
        x, y = 0, 0
        
        cx, cy = 0, 0
        for c in s:
            dx, dy = d[c]
            cx += dx
            cy += dy
            
            if cx != 0 or cy != 0:
                vx, vy = 0, 0
                
                for c in s:
                    tx, ty = d[c]
                    
                    if vx + tx != cx or vy + ty != cy:
                        vx += tx
                        vy += ty
                
                if vx == 0 and vy == 0:
                    x, y = cx, cy
        
        outs.append(f'{x} {y}')

    print('\n'.join(outs))