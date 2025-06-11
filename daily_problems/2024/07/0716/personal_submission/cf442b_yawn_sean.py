# Submission Link: https://codeforces.com/contest/442/submission/270783399
def main():
    n = II()
    probs = LFI()
    probs.sort(reverse=True)

    p0, p1 = 1, 0
    ans = 0

    for p in probs:
        p1 = p1 * (1 - p) + p0 * p
        p0 *= 1 - p
        ans = max(ans, p1)

    print(ans)