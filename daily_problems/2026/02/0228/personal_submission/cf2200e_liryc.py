'''
https://codeforces.com/contest/2200/submission/364779862
'''
# Alice Bob games

initPrimes()
# prime_factors: smallest prime element of each number
# cnt: count of different prime elements

def solve(n: int, a: list[int]) -> str:
    global prime_factors, cnt
    if is_sorted(a):
        return "Bob"
    if any(cnt[x] > 1 for x in a):
        return "Alice"
    return "Bob" if is_sorted(prime_factors[x] for x in a) else "Alice"
