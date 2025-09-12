'''
https://codeforces.com/gym/100384/submission/338161773
'''
# bits
def solve(n: int) -> str:
    a = [0] * n
    i, d, x = 1, 2, 0
    while i <= n:
        for j in range(i - 1, n, d):
            a[j] = x
        i, d, x = i << 1, d << 1, x + 1
    return ''.join(chr(x + 97) for x in a)
