'''
https://codeforces.com/gym/106020/submission/380262404
'''
def solve(n: int, a: list[int]) -> int:
    if n == 1:
        return a[0]
    elif n == 2:
        return a[0] ^ a[1] ^ a[0] + a[1]
    else:
        s = sum(a)
        return s ^ s - a[0] ^ s - a[-1] ^ s - a[0] - a[-1]
