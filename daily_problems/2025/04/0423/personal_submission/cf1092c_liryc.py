'''
https://codeforces.com/contest/1092/submission/316810529
'''
# only one string consistent with all inputs
 
def solve(n: int, a: list[str]) -> str:
    if n <= 2:
        return "PS"
    sa = [[] for _ in range(n)]
    ans = [0] * len(a)
    for i, s in enumerate(a):
        sa[len(s)].append(i)
 
    S = ''
    i, j = 1, n - 1
    sss = set()
    while i <= j:
        x1, x2 = sa[i]
        y1, y2 = sa[j]
        if i == j:
            if a[x1] + a[x2] in sss:
                S = a[x1] + a[x2]
            else:
                S = a[x2] + a[x1]
            break
        ss = set()
        if a[x1] + a[y1] == a[y2] + a[x2]:
            ss.add(a[x1] + a[y1])
        if a[x1] + a[y2] == a[y1] + a[x2]:
            ss.add(a[x1] + a[y2])
        if a[x2] + a[y1] == a[y2] + a[x1]:
            ss.add(a[x2] + a[y1])
        if a[x2] + a[y2] == a[y1] + a[x1]:
            ss.add(a[x2] + a[y2])
        if not sss:
            sss = ss
        else:
            sss &= ss
        if len(sss) == 1:
            S = list(sss)[0]
            break
        i, j = i + 1, j - 1
    
    i, j = 1, n - 1
    while i <= j:
        if i == j:
            x, y = sa[i]
            if a[x] + a[y] == S:
                ans[x], ans[y] = 0, 1
            else:
                ans[x], ans[y] = 1, 0
        else:
            x1, x2 = sa[i]
            y1, y2 = sa[j]
            if a[x1] + a[y1] == a[y2] + a[x2] == S:
                ans[x1], ans[x2], ans[y1], ans[y2] = 0, 1, 1, 0
            elif a[x1] + a[y2] == a[y1] + a[x2] == S:
                ans[x1], ans[x2], ans[y1], ans[y2] = 0, 1, 0, 1
            elif a[x2] + a[y1] == a[y2] + a[x1] == S:
                ans[x1], ans[x2], ans[y1], ans[y2] = 1, 0, 1, 0
            else:
                ans[x1], ans[x2], ans[y1], ans[y2] = 1, 0, 0, 1
        i, j = i + 1, j - 1
    return ''.join('S' if x else 'P' for x in ans)
