'''
https://codeforces.com/problemset/submission/1210/322821946
'''
# enum the pair
def solve(n: int, m: int, edges: list[list[int]]) -> int:
    if n <= 6 or m <= 6:
        return m
    ans = 0
    for a, b in combinations(range(7), 2):
        a, b = a + 1, b + 1
        hs = set()
        for u, v in edges:
            u = a if u == b else u
            v = a if v == b else v
            if u > v:
                u, v = v, u
            hs.add((u, v))
        ans = max(ans, len(hs))
    return ans
