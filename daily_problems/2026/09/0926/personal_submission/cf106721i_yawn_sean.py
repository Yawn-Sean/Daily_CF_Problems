# Submission link: https://codeforces.com/gym/106721/submission/391954904
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        xs = []
        ys = []
        
        for _ in range(n):
            x, y = MII()
            xs.append(x)
            ys.append(y)
        
        area = 0
        
        for i in range(n - 2):
            x1, y1 = xs[i + 1] - xs[0], ys[i + 1] - ys[0]
            x2, y2 = xs[i + 2] - xs[0], ys[i + 2] - ys[0]
            
            area += x1 * y2 - x2 * y1
        
        area = abs(area)
        
        perimeter = 0
        
        for i in range(n):
            dx, dy = xs[(i + 1) % n] - xs[i], ys[(i + 1) % n] - ys[i]
            perimeter += math.hypot(dx, dy)
        
        if area >= k * 2: outs.append('0')
        else:
            a = math.pi
            b = perimeter
            c = area / 2 - k
    
            outs.append(f'{-2 * c / (b + math.sqrt(b * b - 4 * a * c)):.10f}')
    
    print('\n'.join(outs))