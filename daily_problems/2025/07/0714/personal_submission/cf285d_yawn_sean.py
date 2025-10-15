# Submission link: https://codeforces.com/contest/285/submission/328790057
def main():
    ans = [0, 1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925, 0]

    n = II()
    mod = 10 ** 9 + 7
    print(ans[n] * math.factorial(n) % mod)