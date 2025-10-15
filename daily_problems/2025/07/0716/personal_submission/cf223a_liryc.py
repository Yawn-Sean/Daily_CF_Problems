'''
https://codeforces.com/contest/223/submission/329133090
'''
# enum and count
def solve(s: str) -> tuple[int, str]:
    max_n, max_l, max_r, n = 0, 0, 0, 0
    match = { ')': '(', ']': '[' }
    stk = []
    for i, c in enumerate(s):
        if c == '(' or c == '[':
            stk.append(~i)
        elif stk and (len(stk) > 1 or stk[-1] < 0):
            j = stk.pop()
            if j >= 0:
                n, j = j, ~stk.pop()
            else:
                n, j = 0, ~j
            if s[j] == match[c]:
                n += 1 if c == ']' else 0
                while stk and stk[-1] >= 0:
                    n += stk.pop()
                if n > max_n:
                    max_n, max_l, max_r = n, ~stk[-1] + 1 if stk else 0, i
                stk.append(n)
            else:
                stk = [~i] 
        else:
            stk = [~i]
    return max_n, s[max_l:max_r + 1] if max_n else ''
