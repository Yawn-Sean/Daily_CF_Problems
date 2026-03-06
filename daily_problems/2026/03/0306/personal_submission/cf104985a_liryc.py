'''
https://codeforces.com/gym/104985/submission/365565893
'''
# simple math
def solve(n: int, va: list[int], ta: list[int]) -> list[float]:
    tc, vc, dc = 0.0, 0.0, 0.0
    vs = sum(va)
    ans = [0.0] * n
    for i in sorted(range(n), key=lambda x: ta[x]):
        if tc == 0.0:
            vc = va[i]
            tc = ta[i]
            ans[i] = tc
        else:
            v = vc / (vs - vc)
            r = va[i] * (ta[i] - tc) - dc * va[i]
            t = r / (va[i] + v * va[i])
            dc += v * t
            tc += t
            vc += va[i]
            ans[i] = tc
    return ans
