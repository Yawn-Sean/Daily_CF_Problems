# Submission link: https://codeforces.com/contest/476/submission/275316760
def main():
    a, b = MII()
    mod = 10 ** 9 + 7
    print(((a * (a + 1) // 2 * b + a) * b * (b - 1) // 2) % mod)