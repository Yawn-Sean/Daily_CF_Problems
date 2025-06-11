def main(ac=FastIO()):
    """
    problem:    https://codeforces.com/problemset/problem/1209/G1
    submission: https://codeforces.com/contest/1209/submission/264242349
    """
    loc = defaultdict(lambda:[-1, -1])
    cnt = defaultdict(int)
    n, _ = ac.read_list_ints()
    a = ac.read_list_ints()
    for i, x in enumerate(a):
        if loc[x][0] == -1: 
            loc[x] = [i, i]
        else: 
            loc[x][1] = i 
        cnt[loc[x][0]] += 1 
    segs = sorted(loc.values())
    b = [segs[0]]
    for l, r in segs[1:]:
        if b[-1][1] < l: b.append([l, r])
        else:
            cnt[b[-1][0]] = max(cnt[b[-1][0]], cnt[l])
            b[-1][1] = max(b[-1][1], r)
    ac.st(sum(r - l + 1 - cnt[l] for l, r in b))
