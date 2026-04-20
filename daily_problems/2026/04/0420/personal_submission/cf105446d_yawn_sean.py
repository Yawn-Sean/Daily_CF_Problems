# Submission link: https://codeforces.com/gym/105446/submission/371753618
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        p, r, y = LFI()
        left, right = -2, 2
        
        def f(x):
            return max(abs(x), abs(x - r), abs((p + y + r) / 2 - x), abs((y + r - p) / 2 - x))
        
        for _ in range(100):
            mid1 = (left * 2 + right) / 3
            mid2 = (left + right * 2) / 3
            
            if f(mid1) < f(mid2): right = mid2
            else: left = mid1
    
        x = (left + right) / 2
        x = round(x, 10)
        outs.append(f'{x} {(p + y + r) / 2 - x} {x - r} {(y + r - p) / 2 - x}')
    
    print('\n'.join(outs))