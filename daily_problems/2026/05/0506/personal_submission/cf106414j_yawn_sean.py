# Submission link: https://codeforces.com/gym/106414/submission/373554593
def main():
    t = II()
    outs = []
    
    step = 2 * 10 ** 8 + 5
    
    for _ in range(t):
        n = II()
        pts = []
        
        for _ in range(n):
            x, y = MII()
            pts.append((x, y))
        
        pts.sort()
        
        ans = []
        
        for x, y in pts:
            ans.append(f'{x} {y}')
            ans.append(f'{x + 1} {y - step}')
        
        ans.append(f'{step} {step}')
        ans.append(f'{-step} {step}')
        
        outs.append(str(len(ans)))
        outs.append('\n'.join(ans))
    
    print('\n'.join(outs))