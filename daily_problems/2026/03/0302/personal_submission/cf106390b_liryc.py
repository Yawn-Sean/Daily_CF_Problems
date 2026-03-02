'''
https://codeforces.com/gym/106390/submission/365078953
'''

# tg: tree graph with node 0-indexed, encoded = (w << 20 | u)
def solve(n: int, tg: list[list[int]]) -> list[int]:
    pr = [-1] * n
    pr[0] = 0
    d = [0] * n
    md = [-1] * n 
    md[0] = 0
    lv = [0] * n
    qu = [0]
    for u in qu:
        for e in tg[u]:
            v, w = e & (1 << 20) - 1, e >> 20 
            if v != pr[u]:
                qu.append(v)
                level = lv[v] = lv[u] + 1
                pr[v] = u
                d[v] = d[u] + w
                md[level] = pmin(md[level], d[v])
    ans = [0] * n
    for u in qu:
        if u:
            ans[u] = pmin(md[lv[u]], ans[pr[u]] + d[u] - d[pr[u]])
    return ans
