'''
https://codeforces.com/gym/106054/submission/381939919
permutations, counting
'''

def solve(n: int, a: list[int]) -> int:
    cn = [0] * n
    for i in range(-1, -n - 1, -1):
        cn[(a[i] + i) % n] += 1
    return sum(x * (x - 1) for x in cn) + n
