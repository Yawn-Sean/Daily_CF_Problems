'''
https://codeforces.com/gym/106032/submission/340685842
'''
# math, rings

# qa: -1 for type1, 0-(N-1) for type2
def solve(n: int, m: int, q: int, a: list[int], qa: list[int]) -> list[int]:
    cn = [0] * (m + 1)
    for x in a:
        cn[x] += 1
    nt = [0] * (m + 1)
    stk = []
    for j in range(m << 1):
        i = (j % m) + 1
        if cn[i] & 1:
            while stk:
                k = stk.pop()
                nt[k] = i
        elif cn[i] and not nt[i]: 
            stk.append(i)
    nShift = 0
    ans = []
    for r in qa:
        if r < 0:
            nShift += 1
        else:
            x = a[r]
            if cn[x] & 1:
                ans.append(x)
            else:
                stop = False
                if nt[x] > 0:
                    d = (nt[x] - x) % m
                    if nShift >= d:
                        stop = True
                if stop:
                    ans.append(nt[x])
                else:
                    ans.append((x - 1 + nShift) % m + 1)
    return ans

