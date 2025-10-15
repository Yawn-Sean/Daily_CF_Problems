'''
https://codeforces.com/problemset/submission/1810/327051617
'''
# math - intervals
def solve(q: int, queries: list[list[int]]) -> list[int]:
    lo, hi = 1, 10 ** 18
    def qry(qa):
        nonlocal lo, hi
        if qa[0] == 1:
            _, a, b, n = qa
            l, h = 1, a
            if n > 1:
                l, h = (a - b) * (n - 2) + a + 1, (a - b) * (n - 1) + a
            if min(h, hi) >= max(l, lo):
                lo, hi = max(l, lo), min(h, hi)
                return 1
            else:
                return 0
        else:
            _, a, b = qa
            if a >= hi:
                return 1
            elif a >= lo:
                return -1
            min_days = (lo - b - 1) // (a - b) + 1
            max_days = (hi - b - 1) // (a - b) + 1
            if min_days == max_days:
                return min_days
            else:
                return -1
    return [qry(qa) for qa in queries]