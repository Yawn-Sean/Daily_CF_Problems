'''
https://codeforces.com/gym/104511/submission/351984145
'''
def solve(n: int, m: int, v: int, s: str, trades: list[list[int]]) -> float:
    ta = []
    for a, x, b, y, c, z in trades:
        x -= 1
        y -= 1
        z -= 1
        ta.append(a, x, b, y, c, z)
    
    ca = [-1] * n
    for i in range(n):
        if s[i] == '1':
            ca[i] = 1
    
    for _ in range(n):
        for a, x, b, y, c, z in ta:
            if ca[x] != -1 and ca[y] != -1:
                if ca[z] == -1: ca[z] = (a * ca[x] + b * ca[y])
                else: ca[z] = min(ca[z], (a * ca[x] + b * ca[y]))
    
    return v / ca[0] if ca[0] != -1 else 0
