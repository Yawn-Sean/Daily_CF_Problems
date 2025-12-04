# Submission link: https://codeforces.com/gym/105401/submission/351697244
def main(): 
    t = II()
    outs = []
    
    LARGE = 10 ** 9
    
    for _ in range(t):
        n = II()
        xs = []
        ys = []
        
        dx, dy = 0, 0
        
        for _ in range(n):
            x, y = MII()
            
            if x or y:
                xs.append(x)
                ys.append(y)
        
        n = len(xs)
        
        dx, dy = xs[0], ys[0]
        g = abs(math.gcd(dx, dy))
        dx //= g
        dy //= g
        
        flg1 = True
        flg2 = True
        for i in range(n):
            if dx * ys[i] != dy * xs[i]:
                flg1 = False
            if dx * xs[i] < 0 or dy * ys[i] < 0:
                flg2 = False
        
        if flg1:
            if flg2:
                outs.append('1')
                outs.append(f'{dx} {dy}')
            else:
                outs.append('2')
                outs.append(f'{dx} {dy}')
                outs.append(f'{-dx} {-dy}')
        else:
            x, y = xs[0], ys[0]
            
            for i in range(1, n):
                nx, ny = xs[i], ys[i]
                if nx * y > ny * x: x, y = nx, ny
            
            flg = True
            for i in range(n):
                nx, ny = xs[i], ys[i]
                if nx * y > ny * x or (nx * y == ny * x and (x * nx < 0 or y * ny < 0)):
                    flg = False
            
            if flg:
                g = math.gcd(x, y)
                x //= g
                y //= g
    
                if y == 0:
                    nx = 0
                    ny = x
                else:
                    ny = pow(x, -1, y)
                    nx = (x * ny - 1) // y
                    if nx * y > ny * x:
                        nx = -nx
                        ny = -ny
                
                outs.append('2')
                outs.append(f'{x} {y}')
                outs.append(f'{nx - LARGE * x} {ny - LARGE * y}')
            else:
                outs.append('3')
                outs.append('1 0')
                outs.append('0 1')
                outs.append('-1 -1')
    
    print('\n'.join(outs))