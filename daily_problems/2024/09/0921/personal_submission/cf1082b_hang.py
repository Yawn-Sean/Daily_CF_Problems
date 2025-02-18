
from collections import Counter
def main():
    n = int(input())
    s = list(input())
    c = Counter(s)
    g = c['G']
    ps = 0
    pg = 0
    cg = 0
    cs = 0
    ans = 0
    for i in range(n):
        if s[i] == 'G':
            cg += 1
            if cs:
                ps = cs
                cs = 0
            if ps == 1:
                ans = max(ans,pg+cg)
                if pg + cg < g:
                    ans = max(ans,pg+cg + 1)
        else:
            cs += 1
            if cg:
                pg = cg
                cg = 0
        if cg < g:
            ans = max(ans, cg + 1)
        ans = max(ans, cg)
    print(ans)
        

main()