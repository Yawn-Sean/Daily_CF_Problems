# Submission link: https://codeforces.com/gym/106369/submission/363400948
def main(): 
    b1, b2, h = MII()
    
    def f(x):
        tmp = [b1 * x, b2 * (h - x), ((b1 + b2) * h - b1 * x - b2 * (h - x)) / 2]
        return max(tmp) - min(tmp)
    
    l, r = 0, h
    
    for _ in range(100):
        mid1 = (l * 2 + r) / 3
        mid2 = (l + r * 2) / 3
        
        if f(mid1) < f(mid2): r = mid2
        else: l = mid1
    
    print(f((l + r) / 2) / 2)