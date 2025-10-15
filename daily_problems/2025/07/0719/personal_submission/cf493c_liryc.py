'''
https://codeforces.com/problemset/submission/493/329702868
'''
# maximum suffix sum
def solve(n: int, a: list[int], m: int, b: list[int]) -> list[int]:
    cn = Counter(a)
    for x in b:
        cn[x] -= 1
    max_c, c, d = 0, 0, 10**9 + 1 
    for k in sorted(cn, reverse=True):
        c += cn[k]
        if c >= max_c:
            max_c, d = c, k
    return [sum(3 if x >= d else 2 for x in a), sum(3 if x >= d else 2 for x in b)]
