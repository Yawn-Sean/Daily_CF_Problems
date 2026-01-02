'''
https://codeforces.com/gym/104468/submission/356140863
'''
# math
def solve(n: int, k: int, sa: list[int]) -> int:
    global MOD, fac
    s = set(sa)
    ans = fac.fac(n)
    ca = [1]
    for i in range(2, n + 1):
        if i - 1 in s:
            ca.append(1)
        else:
            ca[-1] += 1
    for c in ca:
        ans = ans * fac.fac_inv(c) % MOD
    return ans
