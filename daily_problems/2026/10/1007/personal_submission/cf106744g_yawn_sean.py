# Submission link: https://codeforces.com/gym/106744/submission/393377913
def main():
    n, k = MII()
    
    v = k * (k + 1) // 2
    mx = (n + v - 1) // v
    
    ans = [mx] * k
    resid = mx * v - n
    
    for i in range(k - 1, -1, -1):
        x = fmin(resid // (i + 1), mx)
        ans[i] -= x
        resid -= (i + 1) * x
    
    print(' '.join(map(str, ans)))
