def main(ac=FastIO()):
    """
    question: https://codeforces.com/problemset/problem/524/C
    submission: https://codeforces.com/contest/524/submission/265035691
    """
    outs = []
    n, k = ac.read_list_ints()
    a = ac.read_list_ints()
    cnt = defaultdict(int)
    cnt_v = defaultdict(list)
    for x in a: 
        for i in range(1, k + 1):
            cnt[x * i] += 1 
            cnt_v[x * i].append(i)
    
    for v in cnt_v.values():
        v.sort()

    for _ in range(ac.read_int()):
        q = ac.read_int()
        fin = float('inf')
        for x in a: 
            for i in range(1, k + 1):
                v = q - x * i 
                if v == 0: fin = min(fin, i)
                th = int(v % x == 0 and v // x <= k)
                if cnt[v] > th: 
                    vs = cnt_v[v]
                    j = vs[0]
                    if th and v // k == vs[0]: j = vs[1]
                    fin = min(fin, i + j)
        outs.append(-1 if fin > k else fin)

    ac.flatten(outs)
