# Submission link: https://codeforces.com/contest/542/submission/296224246
def main():
    n, T = MII()
    hpq = []

    msk = 2 * 10 ** 6

    for _ in range(n):
        t, q = MII()
        hpq.append(t * msk + msk - q)

    heapify(hpq)

    while hpq[0] // msk < T:
        t, q = divmod(heappop(hpq), msk)
        q = msk - q
        if hpq and hpq[0] // msk == t:
            q += msk - heappop(hpq) % msk
        heappush(hpq, (t + 1) * msk + msk - q)

    print(msk - hpq[0] % msk)