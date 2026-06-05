'''
https://codeforces.com/gym/102860/submission/377375739
counting
'''

def solve(n: int, l: int, a: list) -> int:
    ec, j, h = 0, 0, l + 1 >> 1
    for i in range(n):
        while j + 1 < 2 * n and (a[(j + 1) % n] - a[i]) % n < h:
            j += 1
        ec += comb(j - i, 2)
    return comb(n, 3) - ec


