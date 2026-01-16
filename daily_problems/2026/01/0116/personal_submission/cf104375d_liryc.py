'''
Docstring for daily_problems.2026.01.0116.personal_submission.cf104375d_liryc
'''
def solve(n: int, q: int, a: list[int], qa: list[list[int]]) -> list[int]: 
    a.sort()
    ans = []
    for qry in qa:
        if qry[0] == 1:
            v = qry[1]
            
            if v > a[-1]: a.append(v)
            else:
                p = bisect_right(a, v)
                if p > 0 and a[p - 1] == v: continue
                else: a[p] = v
        
        else:
            l = qry[1]
            r = qry[2]
            ans.append(bisect_right(a, r) - bisect_left(a, l))
    return ans