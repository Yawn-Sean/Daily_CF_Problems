# Submission link: https://codeforces.com/contest/123/submission/309896466
def main():
    a, b, x1, y1, x2, y2 = MII()
    print(fmax(abs((x1 + y1) // (2 * a) - (x2 + y2) // (2 * a)),
            abs((x1 - y1) // (2 * b) - (x2 - y2) // (2 * b))))