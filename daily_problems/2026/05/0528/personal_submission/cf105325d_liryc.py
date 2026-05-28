'''
https://codeforces.com/gym/105325/submission/376356737
'''
def solve(n: int, a: list[int]) -> int:
    df = [0] * (n + 1)
    for x in a:
        l, r = 0, x
        if r > n:
            r = n
        df[l] += 1
        df[r] -= 1
    ac = list(accumulate(df))
    return sum(a) - sum(min(a[i], ac[i]) for i in range(n))
