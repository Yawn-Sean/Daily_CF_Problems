# Submission link: https://codeforces.com/gym/104287/submission/356400628
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        a, b, c = MII()
        outs.append(c - math.gcd(c, math.lcm(a, b)))
    
    print('\n'.join(map(str, outs)))