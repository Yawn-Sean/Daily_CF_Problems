# Submission link: https://codeforces.com/contest/1056/submission/264662082
def main():
    n, m = MII()
    ans = 0

    for i in range(1, m + 1):
        ci = (n - i + m) // m
        for j in range(1, m + 1):
            cj = (n - j + m) // m
            if (i * i + j * j) % m == 0:
                ans += ci * cj

    print(ans)