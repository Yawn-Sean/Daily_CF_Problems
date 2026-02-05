# Submission link: https://codeforces.com/gym/104020/submission/361541746
def main(): 
    n = II()
    pts = []
    
    for _ in range(n):
        pts.append(tuple(MII()))
    
    pts.sort()
    ans = 4 * 10 ** 18
    
    for i in range(n):
        x1, y1, z1 = pts[i]
        for j in range(fmax(i - 100, 0), i):
            x2, y2, z2 = pts[j]
            ans = fmin(ans, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1))
    
    print(math.sqrt(ans))