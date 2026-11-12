# Submission link: https://codeforces.com/gym/106123/submission/398232667
def main():
    n, m = MII()
    
    ans = 0
    
    for i in range(1, n):
        for j in range(1, m):
            if math.gcd(i, j) == 1:
                l = fmin(n - i, i)
                r = fmin(m - j, j)
                ans += l * (m - j) + (n - i) * r - l * r
    
    print(ans)