'''
https://codeforces.com/problemset/submission/141/320474867
'''
# constructive, sorting
def solve(n: int, names: list[str], a: list[int]) -> list[str]:
    sa, ai, ha = [], [], [0] * n
    for c, i in sorted((c, i) for i, c in enumerate(a)):
        if c > len(sa):
            return ["-1"]
        else:
            ai.append(i)
            sa.insert(c, i)
    for j, i in enumerate(sa):
        ha[i] = n + 1 - j
    return [f"{names[i]} {ha[i]}" for i in ai]
