# Submission link: https://codeforces.com/contest/625/submission/327160749
def main():
    n = II()
    a = II()
    b = II()
    c = II()

    ans = 0
    if n >= b and b - c <= a:
        ans = (n - b) // (b - c) + 1
        n -= ans * (b - c)
    ans += n // a

    print(ans)