# Submission link: https://codeforces.com/contest/1056/submission/261442112
def main():
    n = II()
    parent = [-1] + LGMI()
    ans = [1] * n

    for i in range(1, n):
        ans[parent[i]] = 0

    for i in range(n - 1, 0, -1):
        ans[parent[i]] += ans[i]

    print(' '.join(map(str, sorted(ans))))