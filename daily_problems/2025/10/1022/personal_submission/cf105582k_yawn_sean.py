# Submission link: https://codeforces.com/gym/105582/submission/344984494
def main(): 
    n = II()
    pts = []
    
    if n % 2:
        pts.append((0, 0))
        
        x, y = 0, 0
        for i in range(n // 2 - 1):
            y += 25
            pts.append((x, y))
            x += 25
            pts.append((x, y))
        
        x = fmax(x, 25)
        pts.append((x, 0))
        pts.append((x // 25 * 9, -x // 25 * 12))
    
    else:
        pts.append((0, 0))
        
        x, y = 0, 0
        for i in range(n // 2 - 1):
            y += 25
            pts.append((x, y))
            x += 25
            pts.append((x, y))
        
        pts.append((x, 0))
    
    dx, dy = 5, 12
    
    for x, y in pts:
        print(x * dx + y * dy, x * (-dy) + y * dx)