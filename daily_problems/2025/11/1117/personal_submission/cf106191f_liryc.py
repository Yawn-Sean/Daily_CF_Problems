'''
https://codeforces.com/gym/106191/submission/349397700
'''
# Counter, Fenwick Tree
def solve(n: int, a: list[int]) -> int:
    e = randint(10000, 2147483647)
    ps = [0] * n
    nop = 0 # negative - positive
    offsets = defaultdict(list)
    offsets[0 ^ e].append(0)
    for i in range(n):
        ps[i] = a[i]
        if i:
            ps[i] += ps[i - 1]
        nop += 1 if a[i] < 0 else -1
        b = offsets[ps[i] ^ e]
        b.append(nop)
    for b in offsets.values():
        sb = set(b)
        b.clear()
        b.extend(sorted(sb))
    dx = {} 
    dx[0 ^ e] = FenwickTree(len(offsets[0 ^ e]))
    dx[0 ^ e].update(bisect_left(offsets[0 ^ e], 0))
    nop = 0
    ans = 0
    for x, s in zip(a, ps):
        nop += 1 if x < 0 else -1
        if s ^ e in dx:
            ans += dx[s ^ e].query(bisect_left(offsets[s ^ e], nop))
        else:
            dx[s ^ e] = FenwickTree(len(offsets[s ^ e]))
        dx[s ^ e].update(bisect_left(offsets[s ^ e], nop))
    return ans
