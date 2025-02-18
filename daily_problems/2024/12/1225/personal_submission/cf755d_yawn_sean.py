# Submission link: https://codeforces.com/contest/755/submission/298348343
def main():
    n, k = MII()
    k = min(k, n - k)

    fen = FenwickTree(n)
    cur, res = 0, 1

    ans = [-1] * n
    for i in range(n):
        if cur + k <= n: res += fen.rsum(cur + 1, cur + k - 1) + 1
        else: res += fen.rsum(cur + 1, n - 1) + fen.rsum(0, cur + k - n - 1) + 1
        
        fen.add(cur, 1)
        cur = (cur + k) % n
        fen.add(cur, 1)
        ans[i] = res

    print(' '.join(map(str, ans)))