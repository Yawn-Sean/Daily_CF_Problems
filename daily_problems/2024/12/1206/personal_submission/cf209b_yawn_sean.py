# Submission link: https://codeforces.com/contest/209/submission/295139750
def main():
    a, b, c = MII()

    ans = inf
    if a % 2 == b % 2: ans = min(ans, max(a, b))
    if a % 2 == c % 2: ans = min(ans, max(a, c))
    if b % 2 == c % 2: ans = min(ans, max(b, c))

    print(ans)