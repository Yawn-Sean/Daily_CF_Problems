'''
https://codeforces.com/problemset/submission/670/337494768
'''
def solve(n: int, m: int, p: int, s: str, t: str) -> str:
    stk_l = [-1 if c == '(' else 1 for c in s[:p]]
    stk_r = [-1 if c == '(' else 1 for c in s[n - 1:p - 1:-1]]
    
    for c in t:
        if c == 'L':
            if stk_l:
                stk_r.append(stk_l.pop())
        elif c == 'R':
            if stk_r:
                stk_l.append(stk_r.pop())
        else:
            c = stk_l.pop()
            if c == -1:
                while c:
                    c += stk_r.pop()
            else:
                while c:
                    c += stk_l.pop()
            if stk_r:
                stk_l.append(stk_r.pop())
    
    return ''.join('(' if c == -1 else ')' for c in stk_l) + ''.join('(' if c == -1 else ')' for c in stk_r[::-1])
