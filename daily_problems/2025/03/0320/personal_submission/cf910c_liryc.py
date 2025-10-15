'''
https://codeforces.com/contest/910/submission/311499845
'''
# 贪心
def solve(n: int, a: list[str]) -> int:
    cn = Counter()
    nonzero = set()
    for s in a:
        d = 1
        for c in s[::-1]:
            cn[c] += d
            d *= 10
        nonzero.add(s[0])
    used = set()
    ans = 0
    for k, v in cn.most_common():
        for d in range(10):
            if not d in used:
                if d == 0 and k in nonzero:
                    continue
                ans += v * d
                used.add(d)
                break
    return ans
