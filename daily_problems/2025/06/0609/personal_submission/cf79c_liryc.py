'''
https://codeforces.com/problemset/submission/79/323573599
'''
# bruteforce
def solve(s: str, n: int, a: list[str]) -> list[int]:
    ans, pos = 0, 0
    i = 0
    for j in range(1, len(s) + 1):
        for w in a:
            if j - i >= len(w) and s[j - len(w):j] == w:
                i = j - len(w) + 1
        if j - i > ans:
            ans, pos = j - i, i
    return [ans, pos]
