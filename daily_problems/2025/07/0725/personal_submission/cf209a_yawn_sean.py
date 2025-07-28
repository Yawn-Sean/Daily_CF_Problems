# Submission link: https://codeforces.com/contest/209/submission/330633438
def main():
    n = II()
    mod = 10 ** 9 + 7
    
    dp0, dp1 = 0, 0
    
    for i in range(n):
        if i % 2 == 0:
            dp0 = (dp0 + dp1 + 1) % mod
        else:
            dp1 = (dp0 + dp1 + 1) % mod
    
    print((dp0 + dp1) % mod)