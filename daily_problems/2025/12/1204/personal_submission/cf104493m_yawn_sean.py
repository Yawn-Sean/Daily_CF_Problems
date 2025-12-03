# Submission link: https://codeforces.com/gym/104493/submission/351725079
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        r, n, l = MII()
        ans = math.pi * r * r
        ans += l * r * n
        ans += l * l / 2 / math.tan(math.pi / n) * n / 2
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))