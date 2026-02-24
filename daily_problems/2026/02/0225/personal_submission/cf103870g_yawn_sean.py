# Submission link: https://codeforces.com/gym/103870/submission/364192843
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        l, r, m = MII()
        v = 1 << m.bit_length() - 1
        outs.append((r + 1) // v - l // v)
    
    print('\n'.join(map(str, outs)))