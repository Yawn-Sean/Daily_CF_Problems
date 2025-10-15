'''
https://codeforces.com/problemset/submission/898/325217581
'''
# (OTK) num of nums to be changed is fixed, select the minimum ones
def solve(n: int, a: list[int]) -> int:
    half = n >> 1
    squares = [i * i for i in range(31624)]
    square_set = set(squares)
    n_square = 0
    a_tosquare, a_tonons = [], []
    for x in a:
        if x in square_set:
            n_square += 1
            a_tonons.append(1 if x else 2)
        else:
            i = bisect_right(squares, x)
            a_tosquare.append(min(x - squares[i - 1], squares[i] - x))
    n_nons = n - n_square
    ans = 0
    if n_square < half:
        a_tosquare.sort()
        ans = sum(a_tosquare[:half - n_square])
    elif n_nons < half:
        a_tonons.sort()
        ans = sum(a_tonons[:half - n_nons])
    return ans
