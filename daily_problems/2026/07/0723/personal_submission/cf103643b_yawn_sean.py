# Submission link: https://codeforces.com/gym/103643/submission/383829057
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        x, y = MII()
        
        vis = set()
        
        vis.add((x - y, 1))
        vis.add((y - x, 1))
        vis.add((x + y, 1))
        
        g = math.gcd(x, y)
        vis.add((x * y, 1))
        vis.add((x // g, y // g))
        vis.add((y // g, x // g))
    
        outs.append(len(vis))
    
    print('\n'.join(map(str, outs)))