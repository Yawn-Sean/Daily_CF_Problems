# Submission link: https://codeforces.com/gym/105442/submission/378951412
def main():
    n = II()
    ans = 10 ** 9
    
    for _ in range(n):
        a, b, c, d, e = MII()
        ans = fmin(ans, min(a + d, b + e, a + c + e, b + c + d))
    
    print(ans)