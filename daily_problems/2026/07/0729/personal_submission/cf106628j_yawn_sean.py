# Submission link: https://codeforces.com/gym/106628/submission/384570845
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        s = I()
        n = len(s)
        
        z = z_algorithm(s)
        rev_z = z_algorithm(s[::-1])
        rev_z.reverse()
        
        ans = 0
        
        for i in range(n - 1, 1, -1):
            x = fmin(i - 1, z[i])
            y = fmin(n - i, rev_z[i - 1])
            y = fmin(i - 1, y)
            ans += fmax(0, x + y - i + 1)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))