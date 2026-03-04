'''
https://codeforces.com/gym/104574/submission/365332340
'''
def solve(a: list[int]) -> bool: 
    for _ in range(8):
        b = []
        for i in range(26):
            b.append(a[i])
            b.append(a[i + 26])
        a = b
        ok = True
        for i in range(26, 52):
            if a[i] == 1:
                ok = False
        if ok: 
            return True
    return False    
