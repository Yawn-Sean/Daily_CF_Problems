# Submission link: https://codeforces.com/contest/615/submission/281923056
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    degs = [0] * n

    for _ in range(m):
        u, v = GMI()
        if u > v:
            u, v = v, u
        path[u].append(v)
        degs[u] += 1
        degs[v] += 1

    dp = [1] * n
    for i in range(n):
        for j in path[i]:
            dp[j] = fmax(dp[j], dp[i] + 1)

    print(max(x * y for x, y in zip(dp, degs)))