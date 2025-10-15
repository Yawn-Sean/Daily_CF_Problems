# Submission link: https://codeforces.com/contest/185/submission/295675234
def main():
    s = II()
    a, b, c = MII()

    if a or b or c:
        tot = a + b + c
        print(s * a / tot, s * b / tot, s * c / tot)
    else:
        print(0, 0, s)