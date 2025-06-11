# Submission link: https://codeforces.com/contest/621/submission/288821322
def main():
    n, p = MII()

    probs = []

    for _ in range(n):
        l, r = MII()
        probs.append((r // p - (l - 1) // p) / (r - l + 1))

    ans = 0
    for i in range(n):
        ans += probs[i] + probs[i - 1] - probs[i] * probs[i - 1]

    print(ans * 2000)