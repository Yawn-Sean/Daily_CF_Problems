# Submission link: https://codeforces.com/gym/106020/submission/380103475
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        
        if n == 2:
            if k & -k == k: outs.append(1)
            else: outs.append(0)
        else:
            v = k - n
            if n % 2 == 0 and k - n == n // 2 + 1: outs.append(1)
            else: outs.append(fmax(0, n - 1 - 2 * v))
    
    print('\n'.join(map(str, outs)))