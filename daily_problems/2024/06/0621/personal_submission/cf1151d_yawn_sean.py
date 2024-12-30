# Submission link: https://codeforces.com/contest/1151/submission/266605725
def main():
    n = II()
    ans = 0

    tmp = []
    for _ in range(n):
        a, b = MII()
        ans += b * n - a
        tmp.append(a - b)

    tmp.sort()
    for i in range(n):
        ans += tmp[i] * (n - i)

    print(ans)