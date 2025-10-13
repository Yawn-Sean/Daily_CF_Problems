'''
https://codeforces.com/gym/103855/submission/343463417
'''
# permutations, counting
def solve(n: int, a: list[int]) -> int:
    MOD = 10**9 + 7
    ans, i, x = 1, 0, a[0]
    for j, y in enumerate(a):
        if y > x:
            ans = ans * (j - i + 1) % MOD
            i, x = j, y
    return ans
