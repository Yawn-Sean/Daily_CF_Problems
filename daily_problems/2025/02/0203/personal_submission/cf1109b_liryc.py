'''
https://codeforces.com/problemset/submission/1109/304202174
'''
# 分类讨论
def solve(s: str) -> str:
    n = len(s)
    if s.count(s[0]) >= n - 1:
        return "Impossible"
    while n and n & 1 == 0:
        n >>= 1
        if s[:n] != s[n:n * 2]:
            return "1"
    return "2"
