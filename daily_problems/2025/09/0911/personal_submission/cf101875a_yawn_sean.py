# Submission link: https://codeforces.com/gym/101875/submission/337901687
def main():
    n, k = MII()
    g = math.gcd(n, k)
    print((n - g) * k + (g - 1) * (k - 1))