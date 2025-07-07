# Submission link: https://codeforces.com/contest/49/submission/327854334
def main():
    n = II()
    s = I()

    v = 0
    for i in range(n):
        v += int(s[i]) != i % 2

    print(fmin(v, n - v))