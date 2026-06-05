'''
https://codeforces.com/gym/102860/submission/377398118
counting
'''
def solve(n: int, l: int, a: list) -> int:
    a.sort()
    ec, j, h = 0, 0, l + 1 >> 1
    if a[-1] - a[0] < h:
        return 0
    for i in range(n):
        while j + 1 < i + n and (a[(j + 1) % n] - a[i]) % l < h:
            j += 1
        ec += comb(j - i, 2)
    return comb(n, 3) - ec
