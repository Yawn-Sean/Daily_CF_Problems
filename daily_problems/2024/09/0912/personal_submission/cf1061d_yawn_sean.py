# Submission link: https://codeforces.com/contest/1061/submission/280792490
def main():
    n, x, y = MII()

    ls = []
    rs = []

    ans = 0
    mod = 10 ** 9 + 7

    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r + 1)
        ans += (r + 1 - l) * y % mod
        if ans >= mod: ans -= mod

    st_range = sorted(range(n), key=lambda x: ls[x])

    hpq_using = []
    hpq_used = []

    for i in st_range:
        while hpq_using and hpq_using[0] <= ls[i]:
            heappush(hpq_used, -heappop(hpq_using))
        
        if hpq_used and (x - y) // y >= ls[i] + hpq_used[0]:
            ans += (ls[i] + heappop(hpq_used)) * y
        else:
            ans += x - y
        
        if ans >= mod: ans -= mod
        heappush(hpq_using, rs[i])

    print(ans)