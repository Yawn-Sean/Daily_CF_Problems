'''
https://codeforces.com/gym/106457/submission/369955640
'''
# diff and prefix sum
def solve(n: int, q: int, sa: list[list[int]], qa: list[int]):
    cn = Counter()
    for a, b in sa:
        cn[a] += 1
        cn[b + 1] -= 1
    ka, ia, pa = [], [], []
    i, c, sm = 0, 0, 0
    for k, v in sorted(cn.items()):
        sm += c * (k - i)
        c += v
        ka.append(k)
        ia.append(c)
        pa.append(sm)
        i = k

    def qry(x: int) -> int:
        nonlocal ka, ia, pa
        f = bisect_left(pa, x) - 1
        return (x - pa[f] - 1) // ia[f] + ka[f]

    return [qry(x) for x in qa]
