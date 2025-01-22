# Submission link: https://codeforces.com/contest/134/submission/297985267
def main():
    def f(x, y):
        if x == 0: return -1
        return y // x + f(y % x, x)

    n = II()
    print(min(f(i, n) for i in range(1, n + 1) if math.gcd(i, n) == 1))