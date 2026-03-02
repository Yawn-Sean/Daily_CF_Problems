'''
https://codeforces.com/gym/106390/submission/365076062
'''

# tg: tree graph with node 0-indexed
def solve(n: int, tg: list[list[int]]) -> list[int]:
    pr = [-1] * n
    pr[0] = 0
    d = [0] * n
    md = [0] 
    lv = [0] * n
    qu = [0]
    for u in qu:
        for v, w in tg[u]:
            if v != pr[u]:
                qu.append(v)
                level = lv[v] = lv[u] + 1
                pr[v] = u
                d[v] = d[u] + w
                if level >= len(md):
                    md.append(d[v])
                elif d[v] < md[level]:
                    md[level] = d[v]
    ans = [0] * n
    for u in qu:
        if u:
            ans[u] = pmin(md[lv[u]], ans[pr[u]] + d[u] - d[pr[u]])
    return ans
