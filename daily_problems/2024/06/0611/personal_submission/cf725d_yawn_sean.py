# Submission link: https://codeforces.com/contest/725/submission/265131511
def main():
    n = II()
    x, y = MII()

    ts = []
    ws = []

    for _ in range(n - 1):
        t, w = MII()
        ts.append(t)
        ws.append(w)

    st_range = sorted(range(n - 1), key=lambda x: ts[x])
    ts = [ts[i] for i in st_range]
    ws = [ws[i] for i in st_range]

    pt = n - 2
    hpq = []

    while pt >= 0 and ts[pt] > x:
        heappush(hpq, ws[pt] - ts[pt] + 1)
        pt -= 1

    ans = len(hpq) + 1
    while hpq and x >= hpq[0]:
        x -= heappop(hpq)
        while pt >= 0 and ts[pt] > x:
            heappush(hpq, ws[pt] - ts[pt] + 1)
            pt -= 1
        ans = min(ans, len(hpq) + 1)

    print(ans)