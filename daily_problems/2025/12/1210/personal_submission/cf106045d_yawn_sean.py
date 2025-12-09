# Submission link: https://codeforces.com/gym/106045/submission/352666077
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        r, l, theta = LII()
        theta = theta / 180 * math.pi
        w = 2 * r * math.sin(theta / 2)
        outs.append(math.sqrt(l * l - w * w))
    
    print('\n'.join(map(str, outs)))