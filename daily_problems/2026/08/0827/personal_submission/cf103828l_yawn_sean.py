# Submission link: https://codeforces.com/gym/103828/submission/388448342
def main():
    def f(x):
        if x == 1: return [0]
        return [2 * v for v in f(x - x // 2)] + [2 * v + 1 for v in f(x // 2)]
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        v = f(n)
        
        for i in range(n):
            outs.append(' '.join(str(v[i] * n + v[j] + 1) for j in range(n)))
    
    print('\n'.join(outs))