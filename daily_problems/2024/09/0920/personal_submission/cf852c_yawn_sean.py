# Submission link: https://codeforces.com/contest/852/submission/281923407
def main():
    n = II()
    pts = LII()

    st_range = sorted(range(n), key=lambda x: pts[(x + 1) % n] + pts[x])
    ans = [-1] * n

    for i in range(n):
        ans[st_range[i]] = i

    print(' '.join(map(str, ans)))