# Submission link: https://codeforces.com/contest/960/submission/261113090
def main():
    x, d = MII()

    ans = []
    cur = 1
    for i in range(59, 0, -1):
        v = (1 << i) - 1
        while x >= v:
            ans.extend(cur for _ in range(i))
            cur += d
            x -= v

    print(len(ans))
    print(' '.join(map(str, ans)))