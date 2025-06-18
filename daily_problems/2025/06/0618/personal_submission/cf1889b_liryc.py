'''
https://codeforces.com/problemset/submission/1889/324975543
'''
# (OTK) greedy, sorting
def solve(n: int, c: int, a: list[int]) -> bool:
    sm = a[0]
    for x, i in sorted(((i + 1) * c - x, i) for i, x in enumerate(a) if i):
        sm += a[i]
        b = c * (i + 1)
        if sm < b:
            return False
    return True
