'''
https://codeforces.com/gym/106124/submission/362236103
'''
def solve(n: int, a: list[list[int]]) -> float:
    def distance(i, j):
        nonlocal a
        x1, y1 = a[i]
        x2, y2 = a[j]
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
    si = 0
    for i in range(n):
        if distance(0, i) > distance(0, si):
            si = i
    sa = sorted(range(n), key=lambda x: distance(si, x))
    ans = 0
    for i in range(1, n):
        ans += (distance(sa[i - 1], sa[i])) ** 0.5
    return ans
