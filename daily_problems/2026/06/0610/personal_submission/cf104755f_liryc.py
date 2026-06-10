'''
https://codeforces.com/gym/104755/submission/378040502
'''
def solve(n: int, m: int, A: list[int], B: list[int]) -> list[int]:
    if m < n:
        return []
    bs = set(B)
    la = []
    cp = set()
    a0 = A[0] 
    for b in B:
        c = 2 * a0 - b 
        for a in A:
            if (2 * a - c) not in bs:
                break 
        else:
            la.append(c)
            for a in A:
                cp.add(2 * a - c)
    return la if len(cp) == m else []