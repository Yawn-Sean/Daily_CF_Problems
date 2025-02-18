# Submission link: https://codeforces.com/contest/558/submission/284379794
def main():
    h, q = MII()
    ls = [1 << h - 1]
    rs = [1 << h]

    for _ in range(q):
        i, l, r, ans = LII()
        r += 1
        l <<= h - i
        r <<= h - i
        
        if ans:
            ls.append(l)
            rs.append(r)
        else:
            ls.append(1 << h - 1)
            rs.append(l)
            ls.append(r)
            rs.append(1 << h)

    pts = sorted(set(sorted(ls + rs)))
    cnt = Counter()

    for pt in pts:
        cnt[pt] = 0

    for l in ls:
        cnt[l] += 1

    for r in rs:
        cnt[r] -= 1

    cur = 0
    freq = 0
    start = 0
    for i in range(len(pts) - 1):
        cur += cnt[pts[i]]
        if cur == q + 1:
            freq += pts[i + 1] - pts[i]
            start = pts[i]

    if freq == 0: print('Game cheated!')
    elif freq == 1: print(start)
    else: print('Data not sufficient!')