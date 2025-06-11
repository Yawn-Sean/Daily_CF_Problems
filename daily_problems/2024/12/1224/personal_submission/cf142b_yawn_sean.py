# Submission link: https://codeforces.com/contest/142/submission/298120736
def main():
    n, m = MII()

    if min(n, m) == 1: print(n * m)
    elif min(n, m) == 2:
        v = max(n, m)
        print(v // 4 * 4 + min(v % 4, 2) * 2)
    else:
        print((n * m + 1) // 2)