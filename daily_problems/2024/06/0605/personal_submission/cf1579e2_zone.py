def main(ac=FastIO()):
    """
    question:   https://codeforces.com/problemset/problem/1579/E2
    submission: https://codeforces.com/contest/1579/submission/264204655
    """
    ans = []
    for _ in range(ac.read_int()):
        cnt = SortedList()
        cnt_v = defaultdict(int)
        fin = 0 
        n = ac.read_int()
        a = ac.read_list_ints()
        for x in a: 
            cnt.add(x)
            cnt_v[x] += 1
            l = bisect_left(cnt, x)
            fin += min(l, len(cnt) - l - cnt_v[x])
        ans.append(fin)
    ac.flatten(ans)
