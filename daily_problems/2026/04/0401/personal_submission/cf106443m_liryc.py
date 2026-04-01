'''
20260401 Y1 1400
'''
def solve(n: int, m: int, a: list[int]) -> int: 
    dk = [0] * (m * 2 + 1)
    db = [0] * (m * 2 + 1)
    v = (m + 1) // 2
    for x in a:
        dk[x] += 1
        dk[x + v] -= 1
        db[x] -= x
        db[x + v] += x
        
        dk[x + v] -= 1
        dk[x + m] += 1
        db[x + v] += x + m
        db[x + m] -= x + m
    
    for i in range(m * 2):
        dk[i + 1] += dk[i]
        db[i + 1] += db[i]
    
    ans = [0] * m
    
    for i in range(m * 2):
        ans[i % m] += dk[i] * i + db[i]
    
    return min(ans)