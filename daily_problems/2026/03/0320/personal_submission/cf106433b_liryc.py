'''
20260320 Y1 1400
'''
def solve(n: int, a: list[int]) -> list[int]: 
    cn = [0] * (n + 1)
    for x in a: 
        cn[x] = 1
    lut = [0] * (n + 1)
    c = 1
    for i in range(n):
        if lut[a[i]] == 0:
            lut[a[i]] = c
            c += 1
        
        a[i] = lut[a[i]]
    return a