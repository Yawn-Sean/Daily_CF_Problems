'''
https://codeforces.com/problemset/submission/131/332827516
'''
# sorting+counting
def solve(n: int, m: int, a: list[list[int]]) -> list[int]:
    c1 = defaultdict(list)
    c2 = defaultdict(list)
    c3 = defaultdict(list)
    c4 = defaultdict(list)
    for r, c in a:
        c1[r].append(c)
        c2[c].append(r)
        c3[r + c].append(c)
        c4[r - c].append(c)
    cn = Counter()
    for r, ca in c1.items():
        for x, y in pairwise(sorted(ca)):
            cn[r << 20 | x] += 1
            cn[r << 20 | y] += 1
    for c, ra in c2.items():
        for x, y in pairwise(sorted(ra)):
            cn[x << 20 | c] += 1
            cn[y << 20 | c] += 1
    for s, ca in c3.items():
        for x, y in pairwise(sorted(ca)):
            cn[s - x << 20 | x] += 1
            cn[s - y << 20 | y] += 1
    for d, ca in c4.items():
        for x, y in pairwise(sorted(ca)):
            cn[x + d << 20 | x] += 1
            cn[y + d << 20 | y] += 1
    cn2 = Counter(cn.values())
    ans = [0] * 9
    ans[1:] = (cn2[i] for i in range(1, 9))
    ans[0] = m - sum(ans)
    return ans
