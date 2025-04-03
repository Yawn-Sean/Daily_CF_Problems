'''
https://codeforces.com/problemset/submission/405/313695264
'''
# pairing
def solve(n: int, xa: list[int]) -> list[int]:
    hs = [0] * 500000
    m = 0
    for x in xa:
        if x > 500000:
            hs[1000000 - x] |= 2
            if hs[1000000 - x] == 3:
                m += 1
        else:
            hs[x - 1] |= 1
            if hs[x - 1] == 3:
                m += 1
    ans = []
    for i, x in enumerate(hs):
        if x == 1:
            ans.append(1000000 - i)
        elif x == 2:
            ans.append(i + 1)
        elif x == 0:
            if m:
                ans.append(i + 1)
                ans.append(1000000 - i)
                m -= 1
    return ans