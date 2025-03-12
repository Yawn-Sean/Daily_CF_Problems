'''
https://codeforces.com/problemset/submission/1906/310186178
'''
def solve(n: int, a: list[int]) -> int:
    return min(sum(a) // 3, sum(a) - max(a))
