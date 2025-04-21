'''
https://codeforces.com/problemset/submission/1277/316467874
'''
# counter + set
def solve(n: int, sa: list[str]) -> list[int]:
    c0, c1, c10, c01 = 0, 0, 0, 0 
    s01, s10, ras = set(), set(), set()
    for s in sa:
        if s[0] == s[-1] == '0':
            c0 += 1
        elif s[0] == s[-1] == '1':
            c1 += 1
        elif s[0] == '0': 
            c01 += 1
            rs = s[::-1]
            if rs in s10:
                s10.remove(rs)
            else:
                s01.add(s)
        else:
            c10 += 1
            rs = s[::-1]
            if rs in s01:
                s01.remove(rs)
            else:
                s10.add(s)
    if c01 == c10 == 0:
        if c0 * c1 == 0:
            return []
        else:
            return [-1]
    if len(s01) > len(s10):
        s01, s10 = s10, s01
    x, y = len(s01), len(s10)
    for s in s10:
        if x + 1 >= y:
            break
        ras.add(s)
        x, y = x + 1, y - 1
    return [i + 1 for i in range(n) if sa[i] in ras]