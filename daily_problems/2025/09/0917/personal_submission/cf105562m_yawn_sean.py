# Submission link: https://codeforces.com/gym/105562/submission/338869831
def main():
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    total_area = 0
    for i in range(2, n):
        dx1, dy1 = xs[i - 1] - xs[0], ys[i - 1] - ys[0]
        dx2, dy2 = xs[i] - xs[0], ys[i] - ys[0]
        total_area += dx1 * dy2 - dy1 * dx2
    
    total_triangle_area = 0
    
    pref_x = 0
    pref_y = 0
    
    suff_x = sum(xs)
    suff_y = sum(ys)
    
    for i in range(n):
        x = xs[i]
        y = ys[i]
        
        suff_x -= x
        suff_y -= y
        
        total_triangle_area += (i * x - pref_x) * (suff_y - (n - i - 1) * y) - (i * y - pref_y) * (suff_x - (n - i - 1) * x)
        
        pref_x += x
        pref_y += y
    
    print(total_triangle_area / total_area)