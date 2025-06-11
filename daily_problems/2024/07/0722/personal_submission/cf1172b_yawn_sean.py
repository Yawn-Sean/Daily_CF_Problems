# Submission Link: https://codeforces.com/contest/1172/submission/271839890
def main():
    n = II()
    cnt = [1] * n
    mod = 998244353

    ans = n
    for _ in range(n - 1):
        u, v = GMI()
        ans = ans * cnt[u] % mod * cnt[v] % mod
        cnt[u] += 1
        cnt[v] += 1

    print(ans)