# Submission Link: https://codeforces.com/contest/739/submission/268538779
def main():
    n, q = MII()

    ans = n
    for i in range(q):
        l, r = MII()
        ans = min(ans, r - l + 1)

    print(ans)
    print(' '.join(str(i % ans) for i in range(n)))