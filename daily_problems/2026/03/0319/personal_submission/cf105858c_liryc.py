'''
https://codeforces.com/gym/105858/submission/367317793
'''
# simple math, counter, sorting, greedy
def solve(a: str, b: str) -> int:
    MOD = 998244353
    cn = [0] * 10
    for c in a + b:
        cn[ord(c) - 48] += 1
    an, bn = max(len(a), len(b)), min(len(a), len(b))
    ans = 0
    for i in range(an - 1, -1, -1):
        for _ in range(1 + (i < bn)):
            for x in range(9, 0, -1):
                if cn[x] > 0:
                    cn[x] -= 1
                    ans = (ans + x * pow(10, i, MOD)) % MOD
                    break
    return ans
