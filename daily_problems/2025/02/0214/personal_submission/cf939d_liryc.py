'''
https://codeforces.com/problemset/submission/939/306048159
'''
# Union-find
def solve(n: int, s: str, t: str) -> list[str]:
    uni = UnionFind(26)
    ans = []
    for a, b in zip(s, t):
        x, y = ord(a) - 97, ord(b) - 97
        if not uni.check(x, y):
            uni.union(x, y)
            ans.append(f"{a} {b}")
    return ans
