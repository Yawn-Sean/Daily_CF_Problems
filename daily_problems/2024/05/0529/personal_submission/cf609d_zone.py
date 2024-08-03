def main(ac=FastIO()):
    """
    question:   https://codeforces.com/problemset/problem/609/D
    submission: https://codeforces.com/contest/609/submission/263086824
    """
    n, m, k, s = ac.read_list_ints()
    cost_ma, cost_mb = ac.read_list_ints(), ac.read_list_ints()
    cost_a, cost_b = [], []
    for i in range(1, m + 1):
        a, b = ac.read_list_ints()
        if a == 1: cost_a.append([b, i])
        else: cost_b.append([b, i])
    cost_a.sort()
    cost_b.sort()
    s_a = ac.accumulate([x[0] for x in cost_a])
    s_b = ac.accumulate([x[0] for x in cost_b])

    ans_a = ans_b = -1 
    idx_a = idx_b = -1

    def check(t):
        mn_a, mn_b = min(cost_ma[: t + 1]), min(cost_mb[: t + 1])
        for i, sa in enumerate(s_a):
            if sa > s: break 
            l, r = 0, len(s_b) - 1
            while l < r: 
                mid = l + r + 1 >> 1 
                if sa * mn_a + s_b[mid] * mn_b > s: r = mid - 1
                else: l = mid 
            if i + l >= k and sa * mn_a + s_b[l] * mn_b <= s:
                nonlocal ans_a, ans_b, idx_a, idx_b 
                ans_a, ans_b = i, l 
                idx_a = cost_ma.index(mn_a)
                idx_b = cost_mb.index(mn_b)
                return True 
        return False

    l, r = 0, n - 1 
    while l < r: 
        mid = l + r >> 1 
        if check(mid): r = mid 
        else: l = mid + 1
    check(l)

    if ans_a == ans_b == -1: print(-1)
    else:
        print(l + 1)
        ans = []
        for _, v in cost_a[: ans_a]:
            if len(ans) == k: break 
            ans.append([v, idx_a + 1])
        for _, v in cost_b[: ans_b]:
            if len(ans) == k: break 
            ans.append([v, idx_b + 1])
        print('\n'.join([f'{x[0]} {x[1]}' for x in ans]))
