# Submission link: https://codeforces.com/contest/1041/submission/273637870
def main():
    n, h = MII()
    ls = []
    rs = []
    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)

    l, r = 0, 0
    cur = h

    res = 0
    ans = 0

    while l < n:
        while r < n - 1 and ls[r+1] - rs[r] < cur:
            res += rs[r] - ls[r]
            cur -= ls[r+1] - rs[r]
            r += 1
        ans = max(ans, res + rs[r] - ls[r] + h)
        res -= rs[l] - ls[l]
        l += 1
        if l < n:
            cur += ls[l] - rs[l-1]

    print(ans)