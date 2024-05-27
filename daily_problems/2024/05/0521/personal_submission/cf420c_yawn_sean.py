# Submission link: https://codeforces.com/contest/420/submission/261947109
def main():
    n, p = MII()

    cnts = [0] * n
    tmp = Counter()

    for _ in range(n):
        u, v = GMI()
        cnts[u] += 1
        cnts[v] += 1
        if u > v: u, v = v, u
        tmp[(u, v)] += 1

    ans = 0
    for u, v in tmp:
        if cnts[u] + cnts[v] >= p and cnts[u] + cnts[v] - tmp[(u, v)] < p:
            ans -= 1

    cnts.sort()
    l = 0
    for r in range(n - 1, -1, -1):
        while l < r and cnts[r] + cnts[l] < p:
            l += 1
        if l == r: break
        ans += r - l

    print(ans)