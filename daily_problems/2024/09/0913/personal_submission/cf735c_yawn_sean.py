# Submission link: https://codeforces.com/contest/735/submission/280919532
def main():
    n = II()
    d1, d2 = 2, 1
    cur = 0

    while d1 <= n:
        d1, d2 = d1 + d2, d1
        cur += 1

    print(cur)