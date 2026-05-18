# Submission link: https://codeforces.com/gym/106531/submission/375018866
def main():  
    def dis(x1, y1, x2, y2):
        return abs(x1 - x2) + abs(y1 - y2)
    
    ax, ay, bx, by = MII()
    ans = dis(ax, ay, bx, by)
    
    t = II()
    for _ in range(t):
        b, k = MII()
        
        for x1 in [ax, (ay - b) * k]:
            y1 = k * x1 + b
            for x2 in [bx, (by - b) * k]:
                y2 = k * x2 + b
                
                ans = fmin(ans, dis(ax, ay, x1, y1) + abs(x1 - x2) + dis(x2, y2, bx, by))
    
    print(ans)