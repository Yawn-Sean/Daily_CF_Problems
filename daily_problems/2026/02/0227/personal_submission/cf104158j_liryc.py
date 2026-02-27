'''
20260227 Y1
'''
def solve(n: int, m: int, k: int, a: list[int], qa: list[list[int]]) -> list[int]: 
    a.sort()
    seg = SegTree(pmax, 0, k + 5)
    ans = []
    for l, r, x in qa:
        l -= 1
        if l: seg.set(l, seg.get(l) + x)
        seg.set(r, seg.get(r) - x)
        ans.append(n - bisect_left(a, seg.all_prod()))
    return ans