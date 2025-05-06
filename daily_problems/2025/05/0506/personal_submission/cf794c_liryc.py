'''
https://codeforces.com/problemset/submission/794/318581664
'''
# 贪心+分类讨论
def solve(s: str, t: str) -> str:
    n = len(s)
    ans = [' ' for _ in range(n)]

    cn = [0] * 26
    for c in s:
        cn[ord(c) - 97] += 1
    ns = n + 1 >> 1
    sa = deque()
    for j in range(26):
        while cn[j]:
            sa.append(j)
            cn[j] -= 1
            if len(sa) == ns:
                break
        if len(sa) == ns:
            break
    
    cn[:] = repeat(0, 26)
    for c in t:
        cn[ord(c) - 97] += 1
    nt = n >> 1
    ta = deque()
    for j in range(25, -1, -1):
        while cn[j]:
            ta.append(j)
            cn[j] -= 1
            if len(ta) == nt:
                break
        if len(ta) == nt:
            break

    i, j, flip = 0, n - 1, 0
    for _ in range(n):
        flip ^= 1
        if flip: # Oleg's turn: use s to make string big
            if ta and sa[0] < ta[0]:
                ans[i] = sa[0]
                i += 1
                del sa[0]
            else:
                ans[j] = sa[-1]
                j -= 1
                del sa[-1]
        else: # Igor's turn: use t to make string small
            if sa and ta[0] > sa[0]:
                ans[i] = ta[0]
                i += 1
                del ta[0]
            else:
                ans[j] = ta[-1]
                j -= 1
                del ta[-1]

    return ''.join(chr(x + 97) for x in ans)
