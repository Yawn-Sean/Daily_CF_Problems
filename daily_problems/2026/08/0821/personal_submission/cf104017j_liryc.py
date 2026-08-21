'''
https://codeforces.com/gym/104017/submission/387853182
Math, factors
'''
def solve(w: int, l: int) -> list[int]:
    ans = {1, 2}
    for x in all_factors(gcd(w - 1, l - 1)): 
        ans.add(x)
    for x in all_factors(gcd(w - 2, l)): 
        ans.add(x)
    for x in all_factors(gcd(w, l - 2)): 
        ans.add(x)
    return sorted(ans)
