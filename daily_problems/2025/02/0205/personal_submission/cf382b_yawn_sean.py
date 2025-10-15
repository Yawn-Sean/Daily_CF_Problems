# Submission link: https://codeforces.com/contest/382/submission/304487316
def main():
    a, b, w, x, c = MII()

    if c <= a: print(0)
    else: print(((c - a) * w - b + w - x - 1) // (w - x))