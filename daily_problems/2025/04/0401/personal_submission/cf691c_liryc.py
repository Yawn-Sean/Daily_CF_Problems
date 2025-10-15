'''
https://codeforces.com/problemset/submission/691/313323094
'''
# 高精度/科学计数
def solve(s: str) -> str:
    dot = False
    ans = []
    e = 0
    d = 1
    for c in s:
        if c == '.':
            dot = True
            if ans:
                d = 0
            else:
                e = -1
                d = -1
        elif c == '0':
            if ans:
                e += d
                ans.append(c)
            else:
                if dot:
                    e -= 1
        else:
            if ans:
                ans.append(c)
                if not dot:
                    e += 1
            else:
                ans = [c, '.']
                if dot:
                    d = 0
                else:
                    d = 1
    r = len(ans) - 1
    while ans[r] == '0':
        r -= 1
    if ans[r] == '.':
        r -= 1
    return ''.join(ans[:r + 1]) + ('' if e == 0 else 'E' + str(e))
