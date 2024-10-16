# https://codeforces.com/contest/641/submission/286225067
n = RI()
q = defaultdict(list)
_set = set()
for i in range(n):
    tp, t, v = RII()
    q[v].append((i, tp, t)) # 顺序， 类型， 时间

ans = [-1] * n
for v, a in q.items():
    # 对时间离散化
    m = {e: i for i, e in enumerate(sorted(set([x[2] for x in a])), 1)}
    tree = BIT(len(m) + 1)
    for idx, tp, t in a: # 按顺序处理
        if tp == 1:
            tree.add(m[t], 1)
        elif tp == 2:
            tree.add(m[t], -1)
        else:
            ans[idx] = tree.query(m[t])

print('\n'.join(str(x) for x in ans if x != -1))
    