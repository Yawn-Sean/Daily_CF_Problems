# Submission link: https://codeforces.com/gym/106500/submission/372610970
def main():
    n = II()
    ans = 1
    
    for i in range(1, n + 1):
        ans *= fmin(i, n - i + 1)
    
    print(ans)