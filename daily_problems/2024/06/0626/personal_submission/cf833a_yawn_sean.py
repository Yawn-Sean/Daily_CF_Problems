# Submission Link: https://codeforces.com/contest/833/submission/267443155
def main():
    a, b = MII()
    l, r = 1, 10 ** 6
    while l <= r:
        m = (l + r) // 2
        if m ** 3 > a * b: r = m - 1
        else: l = m + 1
    return 'Yes' if a * b == r ** 3 and a % r == 0 and b % r == 0 else 'No'