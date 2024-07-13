# Submission Link: https://codeforces.com/contest/1059/submission/270250708
def main():
    n = II()

    def f(n):
        if n <= 3:
            return [1] * (n - 1) + [n]
        return [1] * (n - n // 2) + [x * 2 for x in f(n // 2)]

    print(' '.join(map(str, f(n))))