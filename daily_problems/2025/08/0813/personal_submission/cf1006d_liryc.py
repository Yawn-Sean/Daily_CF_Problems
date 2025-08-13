'''
https://codeforces.com/problemset/submission/1006/333794517
'''
# counting, discuss cases
def solve(n: int, sa: str, sb: str) -> int:
    ans = 0
    if n & 1 and sa[n >> 1] != sb[n >> 1]:
        ans += 1
    i, j = 0, n - 1
    while i < j:
        di = { k : sum(1 for _ in g) for k, g in groupby(sorted([sa[i], sb[i], sa[j], sb[j]]))}
        if len(di) == 4:
            ans += 2
        elif len(di) == 3:
            ans += 2 if sa[i] == sa[j] else 1
        elif len(di) == 2:
            ans += 1 if max(di.values()) == 3 else 0
        # else len == 1 -> ans += 0
        i, j = i + 1, j - 1
    return ans
