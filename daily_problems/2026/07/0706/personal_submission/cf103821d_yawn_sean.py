# Submission link: https://codeforces.com/gym/103821/submission/381340086
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        n += 1
        
        v = math.isqrt(n)
        if v * v == n:
            outs.append(str(v - 1))
            outs.append(' '.join(map(str, range(1, v))))
        else:
            outs.append('-1')
    
    print('\n'.join(outs))