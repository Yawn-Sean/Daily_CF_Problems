'''
https://codeforces.com/gym/104755/submission/378040502
'''
def solve(n: int, m: int, A: list[int], B: list[int]) -> list[int]:
    bs = set(B)
    if m < n:
        return []
    la = []
    cp = set()
    a0 = A[0] 
    for b in B:
        c = 2 * a0 - b 
        va = True
        for a in A:
            if (2 * a - c) not in bs:
                va = False
                break 
        if va:
            la.append(c)
            for a in A:
                cp.add(2 * a - c)
    if len(cp) == m:
        return la
    else:
        return []