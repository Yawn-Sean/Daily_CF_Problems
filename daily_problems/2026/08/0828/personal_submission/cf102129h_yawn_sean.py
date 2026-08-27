# Submission link: https://codeforces.com/gym/102129/submission/388537569
def main():
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        m = II()
        v = (2 * m + 1 - math.isqrt(2 * m * m + 2 * m + 1)) // 2
        
        for k in range(v - 1, v + 1):
            if k == m: continue
            A = m * m + m - 2 * (k * k + k)
            B = 4 * (m - k)
            
            if A // B == k:
                outs.append(A * pow(B, -1, mod) % mod)
                break
    
    print('\n'.join(map(str, outs)))