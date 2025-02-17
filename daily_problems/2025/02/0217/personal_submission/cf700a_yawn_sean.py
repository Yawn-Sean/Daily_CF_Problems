# Submission link: https://codeforces.com/contest/700/submission/306465778
def main():
    n, l, v1, v2, k = MII()
    group = (n + k - 1) // k
    print(l / v2 * (group * (v1 + v2) + (group - 1) * (v2 - v1)) / (group * (v1 + v2) - (group - 1) * (v2 - v1)))