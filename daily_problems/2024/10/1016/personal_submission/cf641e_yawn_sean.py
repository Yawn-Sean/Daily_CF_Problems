# Submission link: https://codeforces.com/contest/641/submission/286148507
def main():
    q = II()
    queries = defaultdict(list)

    rnd = random.getrandbits(30)

    for q_idx in range(q):
        a, t, x = MII()
        x ^= rnd
        queries[x].append((t * q + q_idx) * 3 + a - 1)

    ans = [-1] * q

    for x in queries.values():
        ts = sorted(set(sorted(v // q // 3 for v in x)))
        k = len(ts)
        d = {v: i for i, v in enumerate(ts)}
        
        fen = FenwickTree(k)
        for query in x:
            query, a = divmod(query, 3)
            t, q_idx = divmod(query, q)
            
            if a == 0: fen.add(d[t], 1)
            elif a == 1: fen.add(d[t], -1)
            else: ans[q_idx] = fen.sum(d[t])

    print('\n'.join(str(x) for x in ans if x != -1))