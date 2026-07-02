# Submission link: https://codeforces.com/gym/106607/submission/381019472
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, k = MII()
        ans = n

        if ans % 2 != k % 2:
            ans -= 1
        ans = fmin(ans, k)
        if m % 2 == 0:
            ans = fmin(ans, n * m - k)
    
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))