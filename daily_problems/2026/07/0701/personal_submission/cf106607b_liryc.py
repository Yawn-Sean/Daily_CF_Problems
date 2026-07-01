'''
https://codeforces.com/gym/106607/submission/380906523
cases
'''
def solve(n: int, a: list[int]) -> int:
    if all(x == 1 for x in a):
        return 0
    i, j = min(i for i, x in enumerate(a) if x != 1), max(i for i, x in enumerate(a) if x != 1)
    if all(a[k] == a[i] for k in range(i, j + 1)):
        return 1
    return 2