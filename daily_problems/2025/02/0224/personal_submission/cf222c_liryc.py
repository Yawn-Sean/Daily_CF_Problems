'''
https://codeforces.com/problemset/submission/222/307488049
'''
# prime factors
# 必须在原数组上约减，重新组合有可能数组长度会爆
def solve(n: int, m: int, a: list[int], b: list[int]) -> list[list[int]]:
    global MAXN
    initPrimes()
    ca, cb = Counter(), Counter()
    for c in a:
        for f in prime_elements(c):
            ca[f] += 1
    for c in b:
        for f in prime_elements(c):
            if ca[f]:
                ca[f] -= 1
            else:
                cb[f] += 1
    ra, rb = [1], [1]
    for c in a:
        for f in prime_elements(c):
            if ca[f]:
                ca[f] -= 1
                if ra[-1] * f <= MAXN:
                    ra[-1] *= f
                else:
                    ra.append(f)
    for c in b:
        for f in prime_elements(c):
            if cb[f]:
                cb[f] -= 1
                if rb[-1] * f <= MAXN:
                    rb[-1] *= f
                else:
                    rb.append(f)
    return [ra, rb]
