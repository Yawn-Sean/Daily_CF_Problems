'''
https://codeforces.com/gym/105863/submission/352933114
'''
# binary search
def solve(n: int, q: int, a: list[int], queries: list[int]) -> list[int]:
    b = []
    for x in a:
        if not b or b[-1] > x:
            b.append(x)
    b.reverse()
    def qry(x: int) -> int:
        nonlocal b
        i = 0
        while i >= 0:
            i = bisect_right(b, x) - 1
            if i >= 0:
                x %= b[i]
        return x
    return [qry(x) for x in queries]
