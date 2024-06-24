def main(ac=FastIO()):
    """
    question: https://codeforces.com/problemset/problem/1461/D
    submission: https://codeforces.com/contest/1461/submission/264550034
    """
    rnd = random.getrandbits(25)

    outs = []
    for _ in range(ac.read_int()):
        n, q = ac.read_list_ints()
        a = [0] + ac.read_list_ints()
        a.sort() 
        s = ac.accumulate(a[1:])

        vis = set() 

        def dfs(l, r):
            vis.add(s[r] - s[l - 1] + rnd)
            if a[l] == a[r]: return 
            mid = bisect_right(a, a[l] + a[r] >>1 )
            dfs(l, mid - 1)
            dfs(mid, r)
        dfs(1, n)
        for _ in range(q):
            s_i = ac.read_int()
            outs.append("Yes" if s_i + rnd in vis else "No")

    ac.flatten(outs)
