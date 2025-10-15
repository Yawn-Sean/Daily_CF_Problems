'''
https://codeforces.com/problemset/submission/1281/303796635
'''
# 找一个最优解，然后与c比较
def solve(s: str, c: str) -> str:
    t = s
    for i, (a, b) in enumerate(zip(s, sorted(s))):
        if b < a:
            f = s.rindex(b)
            t = s[:i] + b + s[i + 1:f] + a + s[f + 1:]
            break
    if t < c:
        return t
    else:
        return "---"
