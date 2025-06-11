# Submission link: https://codeforces.com/contest/643/submission/307068488
def main():
    n, k = MII()
    a, b, c, d = MII()

    if n == 4 or k <= n: print(-1)
    else:
        tmp = [i for i in range(1, n + 1) if i != a and i != b and i != c and i != d]
        print(a, c, *tmp, d, b)
        print(c, a, *tmp, b, d)