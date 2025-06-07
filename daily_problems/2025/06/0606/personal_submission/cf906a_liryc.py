'''
https://codeforces.com/problemset/submission/906/323077945
'''
# (OTK) sets
def solve(n: int, actions: list[str], words: list[str]) -> int:
    s = set(chr(c) for c in range(97, 97 + 26))
    ans = 0
    for a, w in zip(actions[:-1], words[:-1]):
        if len(s) == 1:
            if a != '.':
                ans += 1
        else:
            if a == '.' or a == '?':
                s = s - set(w)
            else:
                s = s & set(w)
    return ans
