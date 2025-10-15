'''
https://codeforces.com/problemset/submission/67/334329942
'''
# 山脉数组
def solve(n: int, s: str) -> list[int]:
    a = [1] * n 
    p = 0 
    for i, c in enumerate(s):
        if c == 'R':
            if not p:
                p = 1
            p += 1
            a[i + 1] = p
        elif c == '=':
            if p:
                a[i + 1] = p
        else:
            p = 0
    p = 0 
    for j in range(n - 2, -1, -1):
        c = s[j]
        if c == 'L':
            if not p:
                p = 1
            p += 1
            if p > a[j]:
                a[j] = p
            else:
                p = 0
        elif c == '=':
            if p:
                a[j] = p
        else:
            p = 0
    return a
