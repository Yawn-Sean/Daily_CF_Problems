# Submission link: https://codeforces.com/gym/106054/submission/381831462
def main():
    n = II()
    p = LGMI()
    
    d = [0] * n
    ans = 0
    
    for i in range(n):
        x = (i + p[i]) % n
        d[x] += 1
        ans += d[x]
    
    print(2 * ans - n)