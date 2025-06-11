'''
https://codeforces.com/problemset/submission/214/311638513
'''
# greedy + math
def solve(n: int, a: list[int]) -> str:
    a.sort()
    if a[0] != 0:
        return "-1"
    x1, y1, x2, y2 = 0, 0, 0, 0
    for d in a:
        if d % 3 == 1:
            if x1:
                if not y1:
                    y1 = d
            else:
                x1 = d
        elif d % 3 == 2:
            if x2:
                if not y2:
                    y2 = d
            else:
                x2 = d
        if x1 and x2 and y1 and y2:
            break
    sm = sum(a)
    skip = []
    if sm % 3 == 1:
        if x1:
            skip.append(x1)
        else:
            skip += [x2, y2]
    elif sm % 3 == 2:
        if x2:
            skip.append(x2)
        else:
            skip += [x1, y1]
    def getnumbers():
        nonlocal a, skip
        for x in a[::-1]:
            if skip and skip[-1] == x:
                skip.pop()
            else:
                yield str(x)
    ans = ''.join(getnumbers())
    return '0' if len(ans) > 1 and ans[0] == '0' else ans