# Submission link: https://codeforces.com/contest/1083/submission/263194051
def main():
    n, k = MII()
    s = I()
    t = I()

    if k == 1:
        print(n)
        return
    cur = 0
    ans = 0

    for i in range(n):
        cur = cur * 2 + ord(t[i]) - ord(s[i])
        cur = min(cur, k - 1)
        ans += cur + 1

    print(ans)
