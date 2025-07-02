'''
python TLE: https://codeforces.com/problemset/submission/44/326785177
AC(C++): https://codeforces.com/problemset/submission/44/326786411
'''
# O(n^2) enumerations
def solve(n: int, a: list[list[int]]) -> float:
    return min(hypot(a[i][0] - a[0][0], a[i][1] - a[0][1], a[i][2] - a[0][2]) + hypot(a[j][0] - a[0][0], a[j][1] - a[0][1], a[j][2] - a[0][2]) + hypot(a[i][0] - a[j][0], a[i][1] - a[j][1], a[i][2] - a[j][2]) for i, j in combinations(range(1, n), 2)) / 2
