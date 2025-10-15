# Submission link: https://codeforces.com/contest/603/submission/316029572
def main():
    n = II()
    s = I()

    total = 0
    for i in range(1, n):
        if s[i] != s[i - 1]:
            total += 1
    print(fmin(total + 3, n))