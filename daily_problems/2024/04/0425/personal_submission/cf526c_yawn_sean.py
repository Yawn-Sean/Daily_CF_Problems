# Submission link: https://codeforces.com/contest/526/submission/258041982
def main():
    c, hr, hb, wr, wb = MII()
    ans = 0

    for i in range(10 ** 5):
        if wr * i > c: break
        ans = max(ans, i * hr + (c - i * wr) // wb * hb)

    for i in range(10 ** 5):
        if wb * i > c: break
        ans = max(ans, i * hb + (c - i * wb) // wr * hr)

    print(ans)